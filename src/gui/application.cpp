/* application.cpp - Qt-specific application hierarchy root
 *
 * Copyright (c) 2022 Oleg Iarygin <oleg@arhadthedev.net>
 *
 * Distributed under the MIT software license; see the accompanying
 * file LICENSE.txt or <https://www.opensource.org/licenses/mit-license.php>.
 */

#include "application.hpp"
#include "mainwindow.hpp"
#include <build.h>
#include <QtWidgets/QApplication>

static const QString appName = QStringLiteral(PROJECT_NAME);
static const QString appVersion QStringLiteral(PROJECT_VERSION);

static void
initOpenGl()
{
	QSurfaceFormat fmt;
	fmt.setDepthBufferSize(24);
	fmt.setVersion(3, 3);
	fmt.setProfile(QSurfaceFormat::CoreProfile);
	QSurfaceFormat::setDefaultFormat(fmt);
}

int
gui::run_application(int argc, char *argv[])
{
	// https://doc.qt.io/qt-6/qopenglwidget.html:
 	//
	// > Calling QSurfaceFormat::setDefaultFormat() before constructing
	// > the QApplication instance is mandatory on some platforms (for
	// > example, macOS) when an OpenGL core profile context is requested.
	// > This is to ensure that resource sharing between contexts stays
	// > functional as all internal contexts are created using the correct
	// > version and profile.
	initOpenGl();

	QApplication app(argc, argv);
	app.setApplicationName(appName);
	app.setApplicationVersion(appVersion);

	MainWindow window;
	window.show();

	return app.exec();
}
