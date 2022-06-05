/* mainwindow.cpp - Qt-specific application main window
 *
 * Copyright (c) 2022 Oleg Iarygin <oleg@arhadthedev.net>
 *
 * Distributed under the MIT software license; see the accompanying
 * file LICENSE.txt or <https://www.opensource.org/licenses/mit-license.php>.
 */

#include "mainwindow.hpp"
#include <build.h>
#include <QMessageBox>

gui::MainWindow::MainWindow()
	: fileMenu(this->tr("&File"))
	, createAction(this->tr("&Create"))
	, openAction(this->tr("&Open..."))
	, saveAction(this->tr("&Save"))
	, saveAsAction(this->tr("Save &As..."))
	, exitAction(this->tr("Exit"))
	, editMenu(this->tr("&Edit"))
	, undoAction(this->tr("Undo"))
	, redoAction(this->tr("Redo"))
	, cutAction(this->tr("Cut"))
	, copyAction(this->tr("Copy"))
	, pasteAction(this->tr("Paste"))
	, removeAction(this->tr("Remove"))
	, selectAllAction(this->tr("Select All"))
	, invertSelectionAction(this->tr("Invert Selection"))
	, insertMenu(this->tr("&Intert"))
	, insertEllipsoidAction(this->tr("Ellipsoid..."))
	, insertCuboidAction(this->tr("Cuboid..."))
	, helpMenu(this->tr("&Help"))
	, showAboutAction(this->tr("&About Procedural Hero..."))
{
	this->createAction.setShortcuts({QKeySequence::New});
	QObject::connect(&this->createAction, &QAction::triggered,
		         this, &MainWindow::create);

	this->openAction.setShortcuts({QKeySequence::Open});
	QObject::connect(&this->openAction, &QAction::triggered,
		         this, &MainWindow::open);

	this->saveAction.setShortcuts({QKeySequence::Save});
	QObject::connect(&this->saveAction, &QAction::triggered,
		         this, &MainWindow::save);

	this->saveAsAction.setShortcuts({QKeySequence::SaveAs});
	QObject::connect(&this->saveAction, &QAction::triggered,
		         this, &MainWindow::saveAs);

	this->exitAction.setShortcuts({QKeySequence::Quit});
	QObject::connect(&this->exitAction, &QAction::triggered,
		         this, &QWidget::close);

	this->undoAction.setShortcuts({QKeySequence::Undo});
	QObject::connect(&this->undoAction, &QAction::triggered,
		         this, &MainWindow::undo);

	this->redoAction.setShortcuts({QKeySequence::Redo});
	QObject::connect(&this->redoAction, &QAction::triggered,
		         this, &MainWindow::redo);

	this->cutAction.setShortcuts({QKeySequence::Cut});
	QObject::connect(&this->cutAction, &QAction::triggered,
		         this, &MainWindow::cut);

	this->copyAction.setShortcuts({QKeySequence::Copy});
	QObject::connect(&this->copyAction, &QAction::triggered,
		         this, &MainWindow::copy);

	this->pasteAction.setShortcuts({QKeySequence::Paste});
	QObject::connect(&this->pasteAction, &QAction::triggered,
		         this, &MainWindow::paste);

	this->removeAction.setShortcuts({QKeySequence::Delete});
	QObject::connect(&this->removeAction, &QAction::triggered,
		         this, &MainWindow::remove);

	this->selectAllAction.setShortcuts({QKeySequence::SelectAll});
	QObject::connect(&this->selectAllAction, &QAction::triggered,
		         this, &MainWindow::selectAll);

	QObject::connect(&this->invertSelectionAction, &QAction::triggered,
		         this, &MainWindow::invertSelection);

	QObject::connect(&this->insertEllipsoidAction, &QAction::triggered,
		         this, &MainWindow::insertEllipsoid);

	QObject::connect(&this->insertCuboidAction, &QAction::triggered,
		         this, &MainWindow::insertCuboid);

	QObject::connect(&this->showAboutAction, &QAction::triggered,
		         this, &MainWindow::showAbout);

	this->separator11.setSeparator(true);
	this->separator21.setSeparator(true);
	this->separator22.setSeparator(true);

	this->initUi();
}

void
gui::MainWindow::initUi()
{
	this->initUiMenus();
	this->initUiControls();
}

void
gui::MainWindow::initUiMenus()
{
	this->fileMenu.addAction(&this->createAction);
	this->fileMenu.addAction(&this->openAction);
	this->fileMenu.addAction(&this->saveAction);
	this->fileMenu.addAction(&this->saveAsAction);
	this->fileMenu.addAction(&this->separator11);
	this->fileMenu.addAction(&this->exitAction);
	this->topMenu.addMenu(&this->fileMenu);

	this->editMenu.addAction(&this->undoAction);
	this->editMenu.addAction(&this->redoAction);
	this->editMenu.addAction(&this->separator21);
	this->editMenu.addAction(&this->cutAction);
	this->editMenu.addAction(&this->copyAction);
	this->editMenu.addAction(&this->pasteAction);
	this->editMenu.addAction(&this->removeAction);
	this->editMenu.addAction(&this->separator22);
	this->editMenu.addAction(&this->selectAllAction);
	this->editMenu.addAction(&this->invertSelectionAction);
	this->topMenu.addMenu(&this->editMenu);

	this->insertMenu.addAction(&this->insertEllipsoidAction);
	this->insertMenu.addAction(&this->insertCuboidAction);
	this->topMenu.addMenu(&this->insertMenu);

	this->helpMenu.addAction(&this->showAboutAction);
	this->topMenu.addMenu(&this->helpMenu);

	this->setMenuBar(&this->topMenu);
}

void
gui::MainWindow::initUiControls()
{
	this->rootContainer.addWidget(&this->projectView);
	this->rootContainer.addWidget(&this->sceneView);
	this->rootContainer.setStretchFactor(0, 0);
	this->rootContainer.setStretchFactor(1, 1);

	this->setCentralWidget(&this->rootContainer);
}

void
gui::MainWindow::create()
{
}

void
gui::MainWindow::open()
{
}

void
gui::MainWindow::save()
{
}

void
gui::MainWindow::saveAs()
{
}

void
gui::MainWindow::undo()
{
}

void
gui::MainWindow::redo()
{
}

void
gui::MainWindow::cut()
{
}

void
gui::MainWindow::copy()
{
}

void
gui::MainWindow::paste()
{
}

void
gui::MainWindow::remove()
{
}

void
gui::MainWindow::selectAll()
{
}

void
gui::MainWindow::invertSelection()
{
}

void
gui::MainWindow::insertEllipsoid()
{
}

void
gui::MainWindow::insertCuboid()
{
}

static const QString aboutText = QStringLiteral(
	u"<p>" PROJECT_NAME u" version " PROJECT_VERSION u"."
	u"<p>Project page: <a href=\"" PROJECT_URL u"\">" PROJECT_URL u"</a>."
	u"<p>Author: Oleg Iarygin &lt;oleg@arhadthedev.net>."
	u"<p>Copyright \u00A9 2022 Oleg Iarygin &lt;oleg@arhadthedev.net>."
	u"<p>Permission is hereby granted, free of charge, to any person "
	u"obtaining a copy of this software and associated documentation files "
	u"(the \"Software\"), to deal in the Software without restriction, "
	u"including without limitation the rights to use, copy, modify, merge, "
	u"publish, distribute, sublicense, and/or sell copies of the Software, "
	u"and to permit persons to whom the Software is furnished to do so, "
	u"subject to the following conditions:"
	u"<p>The above copyright notice and this permission notice shall be "
	u"included in all copies or substantial portions of the Software. "
	u"<p>THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, "
	u"EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF "
	u"MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND "
	u"NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS "
	u"BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN "
	u"ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN "
	u"CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE "
	u"SOFTWARE."
	u"<p>This program uses the following libraries:"
	u"<ul>"
	u"<li><p>Qt 6 Copyright \u00A9 2016 The Qt Company Ltd."
	u"<p>Alternatively, this file may be used under the terms of the GNU "
	u"Lesser General Public License version 3 as published by the Free "
	u"Software Foundation and appearing in the file LICENSE.LGPL3 included "
	u"in the packaging of this file. Please review the following "
	u"information to ensure the GNU Lesser General Public License version "
	u"3 requirements will be met: "
	u"<a href=\"https://www.gnu.org/licenses/lgpl-3.0.html\">"
	u"https://www.gnu.org/licenses/lgpl-3.0.html</a>.");

void
gui::MainWindow::showAbout()
{
	QMessageBox::information(this, this->showAboutAction.text(), aboutText);
}
