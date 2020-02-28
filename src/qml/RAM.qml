import QtQuick 2.0
import QtQuick.Controls 2.12
import RamInfo 1.0
Item {
    RamInfo{
        id: raminfo
    }

    Column {
        spacing: 1
        anchors.centerIn: parent
        TextArea {
            id: ramtotal
            visible: true
            text: "RAM Total: " + raminfo.totalRam + " KB"
        }
    }
}
