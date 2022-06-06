/* scene3dview.cpp - Qt-specific view for shader tree QAbstractItemModels
 *
 * Copyright (c) 2022 Oleg Iarygin <oleg@arhadthedev.net>
 *
 * Distributed under the MIT software license; see the accompanying
 * file LICENSE.txt or <https://www.opensource.org/licenses/mit-license.php>.
 */

#include "scene_3d_view.hpp"
#include <QtGui/QOpenGLFunctions>

enum PlaneVertexAttributes {
	PlaneVertexPosition
};

static const GLfloat planeVertices[][2] = {{-0.5,  0.5}, { 0.5,  0.5},
                                           {-0.5, -0.5}, { 0.5, -0.5}};
static const GLbyte planeIndices[] = {0, 2, 1, 1, 2, 3};

static const char planeVertexShaderSource[] =
	"#version 330\n"
	"layout(location = 0) in vec2 pos;"
	"void main() {"
		"gl_Position = vec4(pos.xy, 0.0, 1.0);"
	"}\n";

gui::Scene3dView::Scene3dView(QWidget *parent)
	: QOpenGLWidget{parent}
{
}

QSize
gui::Scene3dView::minimumSizeHint() const
{
	return QSize{50, 50};
}

QSize
gui::Scene3dView::sizeHint() const
{
	return QSize{400, 400};
}

void
gui::Scene3dView::setFragmentShader(const char *newSource)
{
	/* Let initializeGL() be called first if queued. */
	QMetaObject::invokeMethod(this, [this, newSource](){
		this->makeCurrent();
		QOpenGLVertexArrayObject::Binder state(&this->plane->state);

		this->plane->fragmentShader.compileSourceCode(newSource);
		this->plane->program.link();
		this->plane->program.bind();

		this->doneCurrent();
	}, Qt::QueuedConnection);
}

void
gui::Scene3dView::initializeGL()
{
	this->plane.emplace();

	// initOpenGl() in application.cpp already set OpenGL 3.3 Core Profile.
	// QOpenGLVertexArrayObject::Binder calls plane.state.create() for us.
	QOpenGLVertexArrayObject::Binder state(&this->plane->state);

	this->plane->vertices.create();
	this->plane->vertices.bind();
	this->plane->vertices.allocate(planeVertices, sizeof(planeVertices));

	this->plane->indices.create();
	this->plane->indices.bind();
	this->plane->indices.allocate(planeIndices, sizeof(planeIndices));

	this->plane->vertexShader.compileSourceCode(planeVertexShaderSource);
	this->plane->program.addShader(&this->plane->vertexShader);
	this->plane->program.addShader(&this->plane->fragmentShader);
	this->plane->program.bindAttributeLocation("pos", PlaneVertexPosition);

	QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

	f->glEnableVertexAttribArray(PlaneVertexPosition);
	f->glVertexAttribPointer(PlaneVertexPosition, 2, GL_FLOAT, GL_FALSE,
	                         2 * sizeof(GLfloat), nullptr);
}

void
gui::Scene3dView::paintGL()
{
	QOpenGLVertexArrayObject::Binder state(&this->plane->state);
	QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

	/*On relatively modern hardware writes nothing but sets a flag. */
	f->glClearColor(1.0, 0.5, 0.0, 1.0);
	f->glClear(GL_COLOR_BUFFER_BIT);
	f->glDrawElements(GL_TRIANGLES, std::ssize(planeIndices),
		          GL_UNSIGNED_BYTE, nullptr);
}

void
gui::Scene3dView::resizeGL(int w, int h)
{
}
