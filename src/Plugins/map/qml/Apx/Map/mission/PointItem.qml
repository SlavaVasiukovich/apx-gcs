import QtQuick 2.5
import QtLocation 5.9
import QtPositioning 5.6
import QtGraphicalEffects 1.0

import APX.Vehicles 1.0
import APX.Mission 1.0

import "../lib"
import ".."

MissionObject {
    id: pointItem
    color: Style.cPoint
    textColor: "white"
    fact: modelData
    implicitZ: 40

    //Fact bindings
    property int f_radius: Math.abs(fact?fact.radius.value:0)
    property int f_hmsl: fact?fact.hmsl.value:0
    property int f_loops: fact?fact.loops.value:0
    property int f_time: fact?fact.timeout.value:0
    property string timeText: fact?fact.timeout.text:""
    property var radiusPointCoordinate: fact?fact.radiusPoint:QtPositioning.coordinate()
    property bool f_ccw: fact?fact.radius.value<0:false
    property int num: fact?fact.num:0

    property bool current: m.piidx.value === num

    function updateRadiusPoint(coord)
    {
        fact.radiusPoint=coord
    }

    //internal
    property bool showDetails: detailsLevel>13

    contentsTop: [
        MapText {
            visible: f_hmsl!==0 && opacity>0
            textColor: "white"
            color: Style.cGreen
            text: f_hmsl+"m"
            opacity: (!dragging)?((hover||selected)?1:(showDetails?(ui.effects?0.6:1):0)):0
        }
    ]

    contentsBottom: [
        MapText {
            visible: (f_loops>0 || f_time>0) && opacity>0
            textColor: "white"
            color: Style.cNormal
            text: (f_loops>0?"L"+f_loops:"")+
                  (f_time>0?"T"+timeText:"")
            opacity: (!dragging)?((hover||selected)?1:(showDetails?(ui.effects?0.6:1):0)):0
        }
    ]


    //Map Items
    property bool circleActive: selected||dragging||hover||radiusPointSelected
    property Item radiusPoint
    property bool radiusPointSelected: radiusPoint && radiusPoint.selected

    Component.onCompleted: {
        createMapComponent(lineC)
        createMapComponent(circleC)
        radiusPoint=createMapComponent(radiusPointC)
    }
    Component {
        id: radiusPointC
        MissionObject {
            id: radiusPoint
            //implicitZ: pointItem.implicitZ-1
            color: "white"
            textColor: "black"
            title: f_radius>0?(apx.distanceToString(f_radius)):"H----"
            opacity: (pointItem.hover || pointItem.selected || selected)?(ui.effects?(f_radius>0?0.8:0.5):1):0
            visible: opacity>0
            implicitCoordinate: radiusPointCoordinate
            interactive: pointItem.selected || selected
            onMoved: {
                updateRadiusPoint(coordinate)
                coordinate=implicitCoordinate //snap
            }
            //direction arrow
            contentsTop: [
                ColorOverlay {
                    id: crsArrow1
                    //z: map.z
                    width: 24
                    height: width
                    opacity: ui.effects?0.8:1
                    visible: (showDetails || circleActive) && (f_ccw)
                    color: "white"
                    source: Image {
                        width: crsArrow1.height
                        height: width
                        source: "../icons/waypoint-course.svg"
                    }
                }
            ]
            contentsBottom: [
                ColorOverlay {
                    id: crsArrow2
                    //z: map.z
                    width: 24
                    height: width
                    rotation: 180
                    opacity: ui.effects?0.8:1
                    visible: (showDetails || circleActive) && (!f_ccw)
                    color: "white"
                    source: Image {
                        width: crsArrow2.height
                        height: width
                        source: "../icons/waypoint-course.svg"
                    }
                }
            ]

        }
    }
    Component {
        id: circleC
        MapCircle {
            id: circle
            //z: -100
            color: circleActive?"#2040FF40":"#100000FF"
            border.color: "#500000FF"
            border.width: 1
            radius: pointItem.f_radius
            center: pointItem.coordinate
            Behavior on radius { enabled: ui.smooth; NumberAnimation {duration: 100;} }
        }
    }
    Component {
        id: lineC
        MapLine {
            id: line
            //z: -10
            visible: circleActive
            //opacity: ui.effects?radiusPoint.opacity/2:1
            line.width: 2
            p1: pointItem.coordinate
            p2: pointItem.radiusPointCoordinate
        }
    }

}
