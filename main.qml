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
            text: "CPU Name: " + sysinfo.cpuName
        }

        TextArea {
            id: cachesize
            visible: true
            text: "Cachce Size: " + sysinfo.cacheSize + "KB"
        }

        TextArea {
            id: cpuMHz
            visible: true
            text: "CPU Frequency: " + sysinfo.cpuMHz + "MHz"    //ПРОБЛЕМА: Данный текст приходится менять в двух местах
        }

        /***
        TextArea{       //Сделать адаптируемым
            id: flags
            visible: true
            text: "Flags: " + sysinfo.flags
            wrapMode: Text.WordWrap
        }
        */

        Timer {
            interval: 1000   //Сделать настраиваемым
            running: true
            repeat: true
            onTriggered: {
                cpuMHz.text = "Cpu Frequency: " + sysinfo.cpuMHz + "MHz"
            }
        }

    }
}
