import QtQuick 2.0
import QtQuick.Controls 2.5

Window {
    property int size
    property int points: 0
    property int xx: 0
    property int yy: 0
    signal start()
    signal stop()

    function cordinates(xxx, yyy){
        root.xx = xxx;
        root.yy = yyy;
    }

    id: root

    width: size
    height: size
    minimumHeight: size
    minimumWidth: size
    maximumHeight: size
    maximumWidth: size

    visible: true
    color: "black"

    // ---- pointField
    Rectangle{
        id: pointField
        width: root.size*(3/5)
        height: root.size/5
        color: "lightblue"
        anchors.top: parent.top
        anchors.left: parent.left

        Text{
            text: "your points: %1".arg(root.points)
            anchors.centerIn: parent
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
            root.start()
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

        onClicked: root.stop()
    }
    // ---- stopButton

    // ---- board
    Rectangle{
        id: board
        width: root.size
        height: root.size*(4/5)
        color: "black"
        anchors.top: pointField.bottom
        clip: true

        Rectangle{
            property int rectSize: root.size/20
            x: root.xx
            y: root.yy
            width: rectSize
            height: rectSize
            radius: rectSize/2
            color: "white"

            MouseArea{
                anchors.fill: parent
                onClicked: points = points + 1
            }
        }
    }
    // ---- board
}
