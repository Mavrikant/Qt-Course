import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Todo List")

    TodoList {
        anchors.centerIn: parent
    }
}
