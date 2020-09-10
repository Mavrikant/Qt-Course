import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Properties and Handlers Demo")

    property string mFirstName: "Serdar"
    onMFirstNameChanged: {
        console.log("The firsname changed to :"+ mFirstName)
    }

    Rectangle {
        width : 300
        height: 100
        color: "greenyellow"
        anchors.centerIn: parent

        MouseArea{
            anchors.fill: parent
            onClicked: {
                mFirstName = "Sabri"
            }
        }
    }

    Component.onCompleted: {
        console.log("The firstname is :"+mFirstName)
    }
}
