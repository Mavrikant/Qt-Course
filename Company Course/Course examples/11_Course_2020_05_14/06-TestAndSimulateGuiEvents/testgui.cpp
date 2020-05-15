/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include <QtTest/QtTest>
#include "mylineedit.h"

//! [0]
class TestGui: public QObject
{
	Q_OBJECT

private slots:
	void testGui_data();
	void testGui();
};
//! [0]

//! [1]
void TestGui::testGui_data()
{
	QTest::addColumn<QTestEventList>("events");
	QTest::addColumn<QString>("expecteds");

	QTestEventList list1;
	list1.addKeyClick('a');
	QTest::newRow("char") << list1 << "a";

	QTestEventList list2;
	list2.addKeyClick('1');
	QTest::newRow("Digit") << list2 << "1";

	QTestEventList list3;
	list3.addKeyClick(' ');
	QTest::newRow("Space") << list3 << " ";

	QTestEventList list4;
	list4.addKeyClick('a');
	list4.addKeyClick(Qt::Key_Backspace);
	QTest::newRow("Backspace") << list4 << "";

	QTestEventList list5;
	list5.addKeyClick('a');
	list5.addKeyClick('1');
	list5.addKeyClick('1');
	list5.addKeyClick(' ');
	QTest::newRow("Combination") << list5 << "a11 ";
}
//! [1]

//! [2]
void TestGui::testGui()
{
	QFETCH(QTestEventList, events);
	QFETCH(QString, expecteds);

	MyLineEdit lineEdit;

	events.simulate(&lineEdit);

	QCOMPARE(lineEdit.text(), expecteds);
}
//! [2]

//! [3]
QTEST_MAIN(TestGui)
#include "testgui.moc"
//! [3]
