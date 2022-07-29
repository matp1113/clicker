import QtQuick 2.0
import QtQuick.Controls 2.5

Window{
    property int size: 400

    id: settingWindow
    width: 620
    height: 480
    color: "white"
    visible: true

    Loader{
        id: loading
    }

    SpinBox{
        id: spiner
        from: 100
        to: 800
        value: 400
        anchors.centerIn: parent
    }

    Button{
        text: "exit settings"
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        onClicked: {
            loading.source = "main.qml"
            loading.item.size = spiner.value
            settingWindow.visible = false
        }
    }
}
