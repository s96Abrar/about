/*
About is for showing CoreApps information.

About is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see {http://www.gnu.org/licenses/}. */

#include "about.h"
#include "ui_about.h"


about::about(QWidget *parent) : QWidget(parent), ui(new Ui::about)
{
    ui->setupUi(this);

    // set stylesheet from style.qrc
    setStyleSheet(Utilities::getStylesheetFileContent(Utilities::StyleAppName::AboutStyle));

    // set window size
    int x = static_cast<int>(Utilities::screensize().width()  * .8);
    int y = static_cast<int>(Utilities::screensize().height()  * .7);
    this->resize(x, y);

    on_coreApps_clicked();
}

about::~about()
{
    delete ui;
}

void about::pageClick(QPushButton *btn, int i, QString title)
{
    // all button checked false
    for (QPushButton *b : ui->shortcut->findChildren<QPushButton*>())
        b->setChecked(false);
    btn->setChecked(true);
    ui->selectedsection->setText(title);
    this->setWindowTitle(title + " - About");
    ui->pages->setCurrentIndex(i);
}

void about::on_releaseNotes_clicked()
{
    pageClick(ui->releaseNotes,1, tr("Relese Notes"));
    QFile p("/usr/share/coreapps/docs/ReleaseNotes");
    p.open(QFile::ReadOnly | QFile::Text );
    QTextStream o(&p);
    ui->pgrelesenotes->setText(o.readAll());
}

void about::on_helpUs_clicked()
{
    pageClick(ui->helpUs,2, tr("Help Us"));
}

void about::on_coreApps_clicked()
{
    pageClick(ui->coreApps,0, tr("CoreApps"));
}
