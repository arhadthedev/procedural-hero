/* application.cpp - Qt-specific application hierarchy root
 *
 * Copyright (c) 2022 Oleg Iarygin <oleg@arhadthedev.net>
 *
 * Distributed under the MIT software license; see the accompanying
 * file LICENSE.txt or <https://www.opensource.org/licenses/mit-license.php>.
 */

#include "application.hpp"
#include <build.h>
#include <QtWidgets/QApplication>

static const QString appName = QStringLiteral(PROJECT_NAME);
static const QString appVersion QStringLiteral(PROJECT_VERSION);

int
gui::run_application(int argc, char *argv[])
{
	QApplication app(argc, argv);
	app.setApplicationName(appName);
	app.setApplicationVersion(appVersion);

	return app.exec();
}
