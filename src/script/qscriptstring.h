/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtScript module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL-ONLY$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QSCRIPTSTRING_H
#define QSCRIPTSTRING_H

#include <QtCore/qstring.h>

#include "qscriptshareddata_p.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Script)

class QScriptStringPrivate;

//internal typedef
typedef QScriptSharedDataPointer<QScriptStringPrivate> QScriptStringPtr;

class Q_SCRIPT_EXPORT QScriptString
{
public:
    QScriptString();
    QScriptString(const QScriptString &other);
    ~QScriptString();

    QScriptString &operator=(const QScriptString &other);

    bool isValid() const;

    bool operator==(const QScriptString &other) const;
    bool operator!=(const QScriptString &other) const;

    quint32 toArrayIndex(bool *ok = 0) const;

    QString toString() const;
    operator QString() const;

private:
    QScriptString(QScriptStringPrivate*);
    QScriptString(QScriptPassPointer<QScriptStringPrivate>);
    QScriptSharedDataPointer<QScriptStringPrivate> d_ptr;
    friend class QScriptValue;
    Q_DECLARE_PRIVATE(QScriptString)
};

Q_SCRIPT_EXPORT uint qHash(const QScriptString &key);

QT_END_NAMESPACE

QT_END_HEADER

#endif // QSCRIPTSTRING_H