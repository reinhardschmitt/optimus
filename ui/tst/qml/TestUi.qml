import QtQuick
import QtTest
import optimus.ui 1.0

TestCase {
    name: "HomeTest"
    when: windowShown
    width: 200; height: 200

    property QtObject mockVM: QtObject { property string data: "" }

    function test_click_updates_mock() {
        let view = Qt.createComponent("qrc:/qt/qml/optimus/ui/qml/Home.qml")
                     .createObject(parent, {viewModel: mockVM})
        
        let input = findChild(view, "inputField")
        let button = findChild(view, "setButton")

        input.text = "Success"
        mouseClick(button)

        compare(mockVM.data, "Success")

        view.destroy()
    }
}
