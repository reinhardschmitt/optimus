import QtQuick
import QtQuick.Controls
import optimus.ui

Rectangle {
    color: "#e0e0e0"
    anchors.fill: parent

    required property SettingsViewModel viewModel

    Column {
        anchors.centerIn: parent
        spacing: 16

        Text {
            text: "⚙️ Settings View"
            font.pixelSize: 24
        }

        TextField {
            id: inputField
            width: 200
        }

        Button {
            text: "Set"
            onClicked: if (viewModel) viewModel.data = inputField.text
        }

        Text {
            text: viewModel ? viewModel.data : ""
            font.pixelSize: 24
        }
    }
}
