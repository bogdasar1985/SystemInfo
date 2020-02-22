import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import SystemInfo 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    minimumHeight:25
    minimumWidth: 95
    title: qsTr("SystemInfo")

    SystemInfo {
        id:sysinfo
    }
    Column {
        spacing: 1
        anchors.centerIn: parent
        TextArea {
            id: cpuname
            visible: true
            text: "CpuName" + sysinfo.cpuName
        }

        TextArea {
            id: cachesize
            visible: true
            text: "CachceSize: " + sysinfo.cacheSize
        }

        TextArea {      //Сделать обновляемым
            id: cpuMHz
            visible: true
            text: "CpuMHz: " + sysinfo.cpuMHz
        }
        /***
        TextArea{       //Сделать адаптируемым
            id: flags
            visible: true
            text: "Flags: " + sysinfo.flags
            wrapMode: Text.WordWrap
        }
        */
    }
}
