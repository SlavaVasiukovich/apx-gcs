TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += lib

SUBDIRS += main
main.depends += lib


# Plugins
PLUGINS += console
PLUGINS += nodes
PLUGINS += map
PLUGINS += telemetry
PLUGINS += compass
PLUGINS += servos
PLUGINS += numbers
PLUGINS += serial
PLUGINS += systree

#PLUGINS += signal
#PLUGINS += sim
#SUBDIRS += joystick

# Utilities
SUBDIRS += pawncc
#SUBDIRS += qgc
#SUBDIRS += qgc-map
#SUBDIRS += gcs-server

#SUBDIRS += xplane

for(subdir, PLUGINS) {
    SUBDIRS += Plugins/$$subdir
    Plugins/$$subdir.depends += lib
}

export(SUBDIRS)
