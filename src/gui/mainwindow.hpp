/* mainwindow.cpp - Qt-specific application main window
 *
 * Copyright (c) 2022 Oleg Iarygin <oleg@arhadthedev.net>
 *
 * Distributed under the MIT software license; see the accompanying
 * file LICENSE.txt or <https://www.opensource.org/licenses/mit-license.php>.
 */

#ifndef PROCHERO_GUI_MAINWINDOW_H
#define PROCHERO_GUI_MAINWINDOW_H

#include "scene_3d_view.hpp"
#include <QtGui/QAction>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>

namespace gui {

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow();

private Q_SLOTS:
	void create();
	void open();
	void save();
	void saveAs();
	void undo();
	void redo();
	void cut();
	void copy();
	void paste();
	void remove();
	void selectAll();
	void invertSelection();
	void insertEllipsoid();
	void insertCuboid();
	void showAbout();

private:
	void initUi();
	void initUiMenus();
	void initUiControls();

	QMenuBar /* +*/ topMenu;
	QMenu /*    |+*/ fileMenu;
	QAction /*  ||-*/ createAction;
	QAction /*  ||-*/ openAction;
	QAction /*  ||-*/ saveAction;
	QAction /*  ||-*/ saveAsAction;
	QAction /*  ||-*/ separator11;
	QAction /*  ||-*/ exitAction;
	QMenu /*    |+*/ editMenu;
	QAction /*  ||-*/ undoAction;
	QAction /*  ||-*/ redoAction;
	QAction /*  ||-*/ separator21;
	QAction /*  ||-*/ cutAction;
	QAction /*  ||-*/ copyAction;
	QAction /*  ||-*/ pasteAction;
	QAction /*  ||-*/ removeAction;
	QAction /*  ||-*/ separator22;
	QAction /*  ||-*/ selectAllAction;
	QAction /*  ||-*/ invertSelectionAction;
	QMenu /*    |+*/ insertMenu;
	QAction /*  ||-*/ insertEllipsoidAction;
	QAction /*  ||-*/ insertCuboidAction;
	QMenu /*    |+*/ helpMenu;
	QAction /*  ||-*/ showAboutAction;

	QSplitter /*     +*/ rootContainer;
	QTreeView /*     |-*/ projectView;
	Scene3dView /*   |-*/ sceneView;
};

} // namespace gui

#endif // PROCHERO_GUI_MAINWINDOW_H
