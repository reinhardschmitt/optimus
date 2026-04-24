import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import optimus.ui

ApplicationWindow {
    id: root
    visible: true
    width: 800
    height: 600

    // Empfängt das Navigator-Objekt aus C++
    required property Navigator nav

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        Row {
            Layout.fillWidth: true
            height: 50
            Button { text: "Home"; onClicked: nav.navigateTo(Page.Home) }
            Button { text: "Settings"; onClicked: nav.navigateTo(Page.Settings) }
        }

        // Dummy Stack für Views
        StackLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true
            
            currentIndex: nav.currentPage 
            
            Rectangle { color: "white"; Text { text: "Home View"; anchors.centerIn: parent } }
            Rectangle { color: "lightgrey"; Text { text: "Settings View"; anchors.centerIn: parent } }
        }
    }
}
