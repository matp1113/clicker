import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQml

Item {
    id: root
    property int size: myAppRoot.getSize()
    property int pointSize: myAppRoot.getPointSize()
    width: size
    height: size

    Window {
        property int points: myGame.receivePoints()
        property string time: "0:00:00"

        id: windowRoot

        width: root.size
        height: root.size
        minimumHeight: size
        minimumWidth: size
        maximumHeight: size
        maximumWidth: size

        visible: true
        color: "black"

        // ---- pointField
        Rectangle{
            id: pointField
            width: root.size*(2/5)
            height: root.size/5
            color: "lightblue"
            anchors.top: parent.top
            anchors.left: parent.left

            Rectangle{
                id: firstText
                anchors.top: parent.top
                color: "lightblue"
                width: parent.width
                height: parent.height/2

                Text{
                    text: "your points: %1".arg(windowRoot.points)
                    anchors.centerIn: parent
                }
            }

            Rectangle{
                id: secondText
                color: "lightblue"
                anchors.top: firstText.bottom
                width: parent.width
                height: parent.height/2

                Text{
                    text: windowRoot.time
                    anchors.centerIn: parent
                }
            }
        }
        // ---- pointField

        // ---- startButton
        Button{
            id: startButton
            width: root.size/5
            height: root.size/5
            anchors.top: parent.top
            anchors.left: pointField.right
            text: "start"

            onClicked: {
                myGame.start();
            }
        }
        // ---- startButton

        // ---- stopButton
        Button{
            id: stopButton
            width: root.size/5
            height: root.size/5
            anchors.top: parent.top
            anchors.left: startButton.right
            text: "stop"

            onClicked: myGame.stop();
        }
        // ---- stopButton

        // ---- quitButton
        Button{
            id: quitButton
            width: root.size/5
            height: root.size/5
            anchors.top: parent.top
            anchors.left: stopButton.right
            text: "exit"

            onClicked: {
                myGame.stop();
                windowRoot.close();
            }
        }
        // ---- quitButton

        // ---- board
        Rectangle{
            id: board
            width: root.size
            height: root.size*(4/5)
            color: "black"
            anchors.top: pointField.bottom
            clip: true

            Rectangle{
                id: gamePoint
                property int rectSize: root.pointSize
                property int xPos: 100;
                property int yPos: 100;
                x: xPos
                y: yPos
                width: rectSize
                height: rectSize
                radius: rectSize/2
                color: "white"

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        myGame.addPoint()
                        windowRoot.points = myGame.receivePoints()
                    }
                }
            }
        }
        // ---- board
    }

    Connections {
        target: myGame

        function onRandomized(xPar, yPar){
            console.log("I received x=" + xPar + ", y=" + yPar)
            gamePoint.xPos = xPar
            gamePoint.yPos = yPar
            console.log("and now xPos=" + gamePoint.xPos + ", yPos=" + gamePoint.yPos)
        }

        function onDockingPoints(gamePoints){
            windowRoot.points = gamePoints
        }

        function onChangedTime(string){
            windowRoot.time = string
        }
    }

}
