import QtQuick 2.0
import QtQuick.Controls 2.12
import CpuInfo 1.0
Item{

    CpuInfo{
        id: cpuinfo
    }

    Column {
        spacing: 1
        anchors.centerIn: parent
        TextArea {
            id: cpuname
            visible: true
            text: "CPU Name: " + cpuinfo.cpuName
        }

        TextArea {
            id: cachesize
            visible: true
            text: "Cachce Size: " + cpuinfo.cacheSize + "KB"
        }

        TextArea {
            id: cpuMHz
            visible: true
            text: "CPU Frequency: " + cpuinfo.cpuMHz + "MHz"    //ПРОБЛЕМА: Данный текст приходится менять в двух местах
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
            interval: 500   //Сделать настраиваемым
            running: true
            repeat: true
            onTriggered: {
                cpuMHz.text = "Cpu Frequency: " + cpuinfo.cpuMHz + "MHz"
            }
        }
    }
}
