// This file is part of qAccordion. An Accordion widget for Qt
// Copyright © 2015 Christian Rapp <0x2a at posteo dot org>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef CLICKABLEFRAME_H
#define CLICKABLEFRAME_H

#include <QFrame>
#include <QMouseEvent>
#include <QString>
#include <QHBoxLayout>
#include <QLabel>
#include <QGraphicsView>

namespace ClickableFrame_constants
{
const char *const CARRET_ICON_CLOSED = ":/qAccordionIcons/caret-right.png";
const char *const CARRET_ICON_OPENED = ":/qAccordionIcons/caret-bottom.png";
}

class ClickableFrame : public QFrame
{

    Q_OBJECT
public:
    explicit ClickableFrame(QString header, QWidget *parent = 0,
                            Qt::WindowFlags f = 0);

    void setClickable(bool status);
    bool getClickable();
    void setHeader(QString header);
    QString getHeader();
    void setNormalStylesheet(QString stylesheet);
    QString getNormalStylesheet();
    void setHoverStylesheet(QString stylesheet);
    QString getHoverStylesheet();

signals:
    void singleClick(QPoint pos);

public slots:

    void setCaretPixmap(QString pixmapPath);

private:
    QLabel *caretLabel;
    QLabel *nameLabel;

    QString hoverStylesheet;
    QString normalStylesheet;

    QString header;
    QString tooltip;

    bool clickable;

    void initFrame();

protected:

    void mousePressEvent(QMouseEvent *event);

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
};

#endif // CLICKABLEFRAME_H
