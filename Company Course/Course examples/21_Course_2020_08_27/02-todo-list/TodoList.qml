import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

import Todo 1.0

ColumnLayout {
    Frame {
        ListView {
            implicitHeight: 250
            implicitWidth:  250
            clip: true

            /*model: ListModel {
            ListElement {
                done: true
                description: "Faturaları öde"
            }

            ListElement {
                done: true
                description: "Evi temizle"
            }

            ListElement {
                done: true
                description: ""
            }
        }*/

            model: TodoModel {
                list: toDoList
            }

            delegate: RowLayout {
                width: parent.width

                CheckBox {
                    checked: model.done
                    onClicked: model.done = checked
                }
                TextField {
                    text: model.description
                    onEditingFinished: model.description = text
                    Layout.fillWidth: true
                }
            }
        }
    }

    RowLayout {
        Button {
            text: qsTr("Add new item")
            onClicked: toDoList.appendItem();
        }

        Button {
            text: qsTr("Remove completed")
            onClicked: toDoList.removeCompletedItems();
        }
    }
}
