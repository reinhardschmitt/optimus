import QtQuick
import QtTest
import "../../qml"

TestCase {
    name: "HomeViewTests"
    when: windowShown

    // --- MOCK VIEWMODEL ---
    // Wir erstellen ein einfaches Objekt, das die 'data' Property besitzt
    QtObject {
        id: mockViewModel
        property string data: "Initial Mock Data"
    }

    // --- COMPONENT UNDER TEST ---
    Home {
        id: homeView
        anchors.fill: parent
        // Hier wird der Mock als ViewModel injiziert
        viewModel: mockViewModel 
    }

    // --- TESTS ---
    function test_initial_display() {
        // Prüfe, ob der Text aus dem Mock korrekt angezeigt wird
        // Wir suchen das Text-Element (evtl. über objectName oder Index)
        let textElement = findChild(homeView, "") // Falls kein objectName vergeben ist
        // In deinem Fall am besten direkt vergleichen:
        compare(homeView.viewModel.data, "Initial Mock Data", "Mock-Daten sollten geladen sein")
    }

    function test_set_button_updates_mock() {
        // 1. Finde das TextField und setze Text
        let input = findChild(homeView, "inputField") // ID 'inputField' in Home.qml nutzen
        input.text = "New Data from Test"

        // 2. Finde den Button und klicke ihn
        let button = findChild(homeView, "setButton") // Füge id: setButton in Home.qml hinzu
        mouseClick(button)

        // 3. Verifiziere, ob das Mock-ViewModel aktualisiert wurde
        compare(mockViewModel.data, "New Data from Test", "ViewModel sollte durch Klick aktualisiert werden")
    }
}
