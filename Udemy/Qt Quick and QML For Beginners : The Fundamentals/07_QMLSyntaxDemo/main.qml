import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id : rootId
    visible: true
    width: 900
    height: 300
    title: qsTr("QML Syntax Demo")

    property string textToShow: "hello"
    property string bottomText: "hello"

    Text{
        id:bottomTextId
        text:bottomText
        font.bold: true
        font.pixelSize: 25
    }

    Row {
        id : row1
        anchors.centerIn: parent
        spacing: 20

        Rectangle {
            id : redRectId
            width: 150; height: 150
            color: "red"
            radius: 20
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Clicked on the red rectangle")
                    textToShow = "red"
                    bottomText=textToShow
                    bottomTextId.color=textToShow
                }
            }

        }
        Rectangle {
            id : greenRectId
            width: 150; height: 150
            color: "green"
            radius: 20
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Clicked on the green rectangle")
                    textToShow = "green"
                    bottomText=textToShow
                    bottomTextId.color=textToShow
                }
            }

        }
        Rectangle {
            id : blueRectId
            width: 150; height: 150
            color: "blue"
            radius: 20
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Clicked on the blue rectangle")
                    textToShow = "blue"
                    bottomText=textToShow
                    bottomTextId.color=textToShow
                }
            }

        }
        Rectangle {
            id : textRectId
            width: 150; height: 150
            color: "dodgerblue"
            radius: 100
            Text {
                id : textId
                anchors.centerIn: parent
                text : textToShow
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Clicked on the blue rectangle")
                    textId.text = "loop"

                }
            }

        }
    }

}


