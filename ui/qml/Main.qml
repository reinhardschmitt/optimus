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

        Component.onCompleted: {
            nav.initialize()
        }

        Loader {
            id: pageLoader
            Layout.fillWidth: true
            Layout.fillHeight: true
            Connections {
                target: nav
                function onCurrentPageChanged() {
                    pageLoader.setSource(nav.currentQml, { "viewModel": nav.currentViewModel });
                }
            }
        }
    }
}
