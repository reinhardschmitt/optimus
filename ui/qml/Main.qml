import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import optimus.ui

ApplicationWindow {
    id: root
    visible: true
    width: 800
    height: 600

    required property Navigator nav

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        // Navigation Header
        ToolBar {
            Layout.fillWidth: true
            RowLayout {
                anchors.fill: parent
                Button { 
                    text: "Home"
                    onClicked: nav.navigateToHome() 
                }
                Button { 
                    text: "Settings"
                    onClicked: nav.navigateToSettings() 
                }
                Button { 
                    text: "Config"
                    onClicked: nav.navigateToConfig() 
                }
            }
        }

        // Der View-Container
        Loader {
            id: pageLoader
            Layout.fillWidth: true
            Layout.fillHeight: true
            source: nav.currentQml

            Binding {
                target: pageLoader.item
                property: "viewModel"
                value: nav.currentViewModel
                when: pageLoader.status === Loader.Ready
            }
        }
    }
}
