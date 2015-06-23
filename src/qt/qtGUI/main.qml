import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Shogi+")
    width: 950
    height: 970
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&New")
                shortcut: "Ctrl+N"
            }

            MenuItem {
                text: qsTr("&Open")
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    Rectangle{
        width:950
        height:950
        color: "#000000"

        Grid{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            columns: 9
            spacing: 5

            //row 1
            Rectangle{
                id: boardSquare
                color: "#E4EFF7"
                width: 100
                height: 100
                border.width: 3
                border.color: "#000000"
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(0,0)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(0,1)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(0,2)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(0,3)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(0,4)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(0,5)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(0,6)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(0,7)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(0,8)
                }
            }


            //row 2
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(1,0)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(1,1)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(1,2)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(1,3)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(1,4)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(1,5)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(1,6)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(1,7)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(1,8)
                }
            }

            //row 3
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(2,0)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(2,1)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(2,2)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(2,3)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(2,4)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(2,5)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(2,6)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(2,7)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(2,8)
                }
            }

            //row 4
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(3,0)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(3,1)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(3,2)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(3,3)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(3,4)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(3,5)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(3,6)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(3,7)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(3,8)
                }
            }

            //row 5
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(4,0)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(4,1)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(4,2)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(4,3)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(4,4)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(4,5)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(4,6)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(4,7)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(4,8)
                }
            }

            //row 6
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(5,0)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(5,1)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(5,2)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(5,3)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(5,4)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(5,5)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(5,6)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(5,7)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(6,8)
                }
            }

            //row 7
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(6,0)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(6,1)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(6,2)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(6,3)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(6,4)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(6,5)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(6,6)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(6,7)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(6,8)
                }
            }

            //row 8
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(7,0)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(7,1)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(7,2)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(7,3)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(7,4)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(7,5)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(7,6)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(7,7)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(7,8)
                }
            }

            //row 9
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(8,0)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(8,1)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(8,2)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(8,3)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(8,4)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(8,5)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(8,6)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(8,7)
                }
            }
            Rectangle{
                color: boardSquare.color
                width: boardSquare.width
                height: boardSquare.height
                border.width: boardSquare.border.width
                border.color: boardSquare.border.color
                MouseArea{
                    anchors.fill: parent
                    onClicked: doSomething(8,8)
                }
            }
        }
    }
}
