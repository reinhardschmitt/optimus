import QtQuick
import QtQuick.Controls
import optimus.ui

Rectangle {
    color: "#e0e0e0"
    anchors.fill: parent

    required property var viewModel

    Column {
        anchors.centerIn: parent
        spacing: 16

        Text {
            text: "🏠 Home View"
            font.pixelSize: 24
        }

        TextField {
            id: inputField
            objectName: "inputField"
            width: 200
        }

        Button {
            id: setButton
            objectName: "setButton"
            text: "Set"
            onClicked: if (viewModel) viewModel.data = inputField.text
        }

        Text {
            text: viewModel ? viewModel.data : ""
            font.pixelSize: 24
        }
    }
}
