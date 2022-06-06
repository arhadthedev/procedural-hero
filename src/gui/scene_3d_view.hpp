/* scene3dview.hpp - Qt-specific view for shader tree QAbstractItemModels
 *
 * Copyright (c) 2022 Oleg Iarygin <oleg@arhadthedev.net>
 *
 * Distributed under the MIT software license; see the accompanying
 * file LICENSE.txt or <https://www.opensource.org/licenses/mit-license.php>.
 */

#ifndef PROCHERO_GUI_SCENE3DVIEW_H
#define PROCHERO_GUI_SCENE3DVIEW_H

#include <QtOpenGL/QOpenGLBuffer>
#include <QtOpenGL/QOpenGLShaderProgram>
#include <QtOpenGL/QOpenGLVertexArrayObject>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <optional>

namespace gui {

class Scene3dView : public QOpenGLWidget {
public:
	explicit Scene3dView(QWidget *parent = nullptr);

	QSize minimumSizeHint() const override;
	QSize sizeHint() const override;

	void setFragmentShader(const char *newSource);

protected:
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int w, int h) override;

private:
	struct VisualObject {
		QOpenGLVertexArrayObject state;
		QOpenGLBuffer vertices{QOpenGLBuffer::VertexBuffer};
		QOpenGLBuffer indices{QOpenGLBuffer::IndexBuffer};
		QOpenGLShader vertexShader{QOpenGLShader::Vertex};
		QOpenGLShader fragmentShader{QOpenGLShader::Fragment};
		QOpenGLShaderProgram program;
	};

	// QOpenGl* class constructors require an initialied OpenGL context
	// so postpone their creation until initializeGL().
	std::optional<VisualObject> plane;
};

} // namespace gui

#endif // PROCHERO_GUI_SCENE3DVIEW_H
