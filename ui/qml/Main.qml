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
                    onClicked: nav.navigateTo(0) 
                }
                Button { 
                    text: "Settings"
                    onClicked: nav.navigateTo(1) 
                }
                Button { 
                    text: "Config"
                    onClicked: nav.navigateTo(2) 
                }
            }
        }

        // Der View-Container
        StackLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            
            currentIndex: nav.currentIndex 

            Home {}     // Index 0
            Settings {} // Index 1
            Config {}   // Index 2
        }
    }
}
