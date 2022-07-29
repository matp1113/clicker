import QtQuick
import QtQuick.Controls 2.5

ApplicationWindow {
    property int size

    id: root
    width: 1000
    height: 800
    visible: true
    title: qsTr("Hello World")

    Loader{
        id: loading
    }

    Rectangle{
        id: rect

        Text{
            text: "Hello there!"
            anchors.centerIn: rect
        }
        color: "grey"
        anchors.top: parent.top
        anchors.bottom: enter.top
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.margins: 30
    }

    Button{
        id: enter
        text: "Come on let's go"
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 10

        onClicked: {
            loading.source = "game.qml"
            loading.item.size = size
            root.visible = false
        }
    }

    Button{
        id: settings
        text: "Let's change something"
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: 10

        onClicked: {
            loading.source = "settings.qml"
            root.visible = false
        }
    }

    Button{
        id: leave
        text: "get me out of there"
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.margins: 10

        onClicked: {
            root.close();
        }
    }
}
