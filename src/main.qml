import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls 1.4
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Styles 1.4
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

    TabView{
        id: tabview
        anchors.fill: parent
        Tab{
            title: "CPU"
            CPU{}
        }

        Tab{
            title: "RAM"
        }

        Tab{
            title: "Network"
        }

        Tab{
            title: "HDD"
        }

        Tab{
            title: "Temperature"
        }
    }
}
