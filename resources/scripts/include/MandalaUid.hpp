// generated file

#pragma once


namespace mandala {

// constants
typedef enum {
    // sns.nav.gyro.src
    gyro_src_unknown = 0,
    gyro_src_local = 1,
    gyro_src_primary = 2,
    gyro_src_secondary = 3,
    gyro_src_failsafe = 4,
    gyro_src_auxillary = 5,

    // sns.nav.acc.src
    acc_src_unknown = 0,
    acc_src_local = 1,
    acc_src_primary = 2,
    acc_src_secondary = 3,
    acc_src_failsafe = 4,
    acc_src_auxillary = 5,

    // sns.nav.mag.src
    mag_src_unknown = 0,
    mag_src_local = 1,
    mag_src_primary = 2,
    mag_src_secondary = 3,
    mag_src_failsafe = 4,
    mag_src_auxillary = 5,

    // sns.nav.gps.src
    gps_src_unknown = 0,
    gps_src_local = 1,
    gps_src_primary = 2,
    gps_src_secondary = 3,
    gps_src_failsafe = 4,
    gps_src_auxillary = 5,

    // sns.nav.gps.fix
    gps_fix_none = 0,
    gps_fix_2D = 1,
    gps_fix_3D = 2,
    gps_fix_DIFF = 3,
    gps_fix_RTK = 4,

    // sns.nav.gps.emi
    gps_emi_unknown = 0,
    gps_emi_ok = 1,
    gps_emi_warning = 2,
    gps_emi_critical = 3,
    gps_emi_spoofing = 4,

    // sns.nav.baro.src
    baro_src_unknown = 0,
    baro_src_local = 1,
    baro_src_primary = 2,
    baro_src_secondary = 3,
    baro_src_failsafe = 4,
    baro_src_auxillary = 5,

    // sns.nav.baro.status
    baro_status_unknown = 0,
    baro_status_available = 1,
    baro_status_warning = 2,
    baro_status_critical = 3,
    baro_status_failure = 4,

    // sns.nav.pitot.src
    pitot_src_unknown = 0,
    pitot_src_local = 1,
    pitot_src_primary = 2,
    pitot_src_secondary = 3,
    pitot_src_failsafe = 4,
    pitot_src_auxillary = 5,

    // sns.nav.pitot.status
    pitot_status_unknown = 0,
    pitot_status_available = 1,
    pitot_status_warning = 2,
    pitot_status_critical = 3,
    pitot_status_failure = 4,

    // sns.nav.agl.src
    agl_src_none = 0,
    agl_src_laser = 1,
    agl_src_radio = 2,
    agl_src_sonic = 3,

    // sns.nav.agl.status
    agl_status_off = 0,
    agl_status_valid = 1,

    // sns.nav.agl.ground
    agl_ground_unknown = 0,
    agl_ground_landed = 1,
    agl_ground_flying = 2,

    // sns.nav.las.status
    las_status_ok = 0,
    las_status_holdon = 1,
    las_status_cancel = 2,

    // sns.env.eng.health
    eng_health_unknown = 0,
    eng_health_idle = 1,
    eng_health_running = 2,
    eng_health_warning = 3,
    eng_health_failure = 4,

    // sns.env.eng.tc
    eng_tc_unknown = 0,
    eng_tc_off = 1,
    eng_tc_active = 2,
    eng_tc_warning = 3,
    eng_tc_critical = 4,
    eng_tc_failure = 5,

    // sns.env.gbox.status
    gbox_status_unknown = 0,
    gbox_status_ok = 1,
    gbox_status_warning = 2,
    gbox_status_failure = 3,

    // sns.env.gbox.clutch
    gbox_clutch_on = 0,
    gbox_clutch_off = 1,
    gbox_clutch_busy = 2,

    // sns.env.prop.status
    prop_status_unknown = 0,
    prop_status_ok = 1,
    prop_status_warning = 2,
    prop_status_failure = 3,

    // sns.env.gen.status
    gen_status_unknown = 0,
    gen_status_ok = 1,
    gen_status_idle = 2,
    gen_status_free = 3,
    gen_status_warning = 4,
    gen_status_failure = 5,

    // sns.env.bat.status
    bat_status_unknown = 0,
    bat_status_ok = 1,
    bat_status_charging = 2,
    bat_status_shutdown = 3,
    bat_status_warning = 4,
    bat_status_failure = 5,

    // sns.env.pwr.status
    pwr_status_unknown = 0,
    pwr_status_ok = 1,
    pwr_status_shutdown = 2,
    pwr_status_warning = 3,
    pwr_status_failure = 4,

    // sns.env.com.status
    com_status_unknown = 0,
    com_status_ok = 1,
    com_status_muted = 2,
    com_status_busy = 3,
    com_status_warning = 4,
    com_status_failure = 5,

    // sns.env.aux.srv
    aux_srv_off = 0,
    aux_srv_on = 1,

    // sns.env.aux.gear
    aux_gear_down = 0,
    aux_gear_retracted = 1,

    // sns.env.ers.status
    ers_status_unknown = 0,
    ers_status_ok = 1,
    ers_status_disarmed = 2,
    ers_status_busy = 3,
    ers_status_failure = 4,

    // sns.env.ers.block
    ers_block_off = 0,
    ers_block_on = 1,

    // sns.env.turret.status
    turret_status_ready = 0,
    turret_status_shooting = 1,
    turret_status_reloading = 2,


    // ctr.nav.eng.starter
    eng_starter_off = 0,
    eng_starter_on = 1,

    // ctr.nav.eng.ign1
    eng_ign1_off = 0,
    eng_ign1_on = 1,

    // ctr.nav.eng.ign2
    eng_ign2_off = 0,
    eng_ign2_on = 1,

    // ctr.nav.eng.fpump
    eng_fpump_off = 0,
    eng_fpump_on = 1,

    // ctr.nav.str.gear
    str_gear_down = 0,
    str_gear_retract = 1,

    // ctr.env.pwr.ap
    pwr_ap_off = 0,
    pwr_ap_on = 1,

    // ctr.env.pwr.servo
    pwr_servo_off = 0,
    pwr_servo_on = 1,

    // ctr.env.pwr.ignition
    pwr_ignition_off = 0,
    pwr_ignition_on = 1,

    // ctr.env.pwr.payload
    pwr_payload_off = 0,
    pwr_payload_on = 1,

    // ctr.env.pwr.agl
    pwr_agl_off = 0,
    pwr_agl_on = 1,

    // ctr.env.pwr.xpdr
    pwr_xpdr_off = 0,
    pwr_xpdr_on = 1,

    // ctr.env.pwr.satcom
    pwr_satcom_off = 0,
    pwr_satcom_on = 1,

    // ctr.env.pwr.rfamp
    pwr_rfamp_off = 0,
    pwr_rfamp_on = 1,

    // ctr.env.pwr.ice
    pwr_ice_off = 0,
    pwr_ice_on = 1,

    // ctr.env.pwr.las
    pwr_las_off = 0,
    pwr_las_on = 1,

    // ctr.env.aux.horn
    aux_horn_off = 0,
    aux_horn_on = 1,

    // ctr.env.ers.launch
    ers_launch_off = 0,
    ers_launch_on = 1,

    // ctr.env.ers.rel
    ers_rel_locked = 0,
    ers_rel_released = 1,

    // ctr.env.light.nav
    light_nav_off = 0,
    light_nav_on = 1,

    // ctr.env.light.taxi
    light_taxi_off = 0,
    light_taxi_on = 1,

    // ctr.env.light.beacon
    light_beacon_off = 0,
    light_beacon_on = 1,

    // ctr.env.light.landing
    light_landing_off = 0,
    light_landing_on = 1,

    // ctr.env.light.strobe
    light_strobe_off = 0,
    light_strobe_on = 1,

    // ctr.env.door.main
    door_main_locked = 0,
    door_main_open = 1,

    // ctr.env.door.drop
    door_drop_locked = 0,
    door_drop_open = 1,

    // ctr.env.cam.rec
    cam_rec_off = 0,
    cam_rec_on = 1,

    // ctr.env.cam.shot
    cam_shot_off = 0,
    cam_shot_single = 1,
    cam_shot_series = 2,

    // ctr.env.cam.arm
    cam_arm_off = 0,
    cam_arm_on = 1,

    // ctr.env.cam.zin
    cam_zin_off = 0,
    cam_zin_on = 1,

    // ctr.env.cam.zout
    cam_zout_off = 0,
    cam_zout_on = 1,

    // ctr.env.turret.op
    turret_op_off = 0,
    turret_op_arm = 1,
    turret_op_shoot = 2,
    turret_op_shooting = 3,
    turret_op_reload = 4,


    // est.nav.att.status
    att_status_unknown = 0,
    att_status_ok = 1,
    att_status_busy = 2,
    att_status_warning = 3,
    att_status_critical = 4,
    att_status_failure = 5,

    // est.nav.att.valid
    att_valid_no = 0,
    att_valid_yes = 1,

    // est.nav.att.mag
    att_mag_unknown = 0,
    att_mag_3D = 1,
    att_mag_HDG = 2,
    att_mag_blocked = 3,
    att_mag_warning = 4,
    att_mag_failure = 5,

    // est.nav.att.rest
    att_rest_no = 0,
    att_rest_yes = 1,

    // est.nav.pos.status
    pos_status_unknown = 0,
    pos_status_ok = 1,
    pos_status_busy = 2,
    pos_status_warning = 3,
    pos_status_critical = 4,
    pos_status_failure = 5,

    // est.nav.pos.valid
    pos_valid_no = 0,
    pos_valid_yes = 1,

    // est.nav.pos.hsrc
    pos_hsrc_none = 0,
    pos_hsrc_baro = 1,
    pos_hsrc_gps = 2,
    pos_hsrc_range = 3,
    pos_hsrc_vision = 4,

    // est.nav.gyro.valid
    gyro_valid_no = 0,
    gyro_valid_yes = 1,

    // est.nav.acc.valid
    acc_valid_no = 0,
    acc_valid_yes = 1,

    // est.nav.lpos.status
    lpos_status_unknown = 0,
    lpos_status_ok = 1,
    lpos_status_busy = 2,
    lpos_status_warning = 3,
    lpos_status_critical = 4,
    lpos_status_failure = 5,

    // est.nav.ref.status
    ref_status_unavailable = 0,
    ref_status_initialized = 1,

    // est.nav.air.stall
    air_stall_unknown = 0,
    air_stall_ok = 1,
    air_stall_warning = 2,
    air_stall_critical = 3,

    // est.nav.wpt.status
    wpt_status_ongoing = 0,
    wpt_status_ok = 1,

    // est.env.sys.mode
    sys_mode_busy = 0,
    sys_mode_ground = 1,
    sys_mode_check = 2,
    sys_mode_taxi = 3,
    sys_mode_ready = 4,
    sys_mode_airborne = 5,

    // est.env.sys.health
    sys_health_unknown = 0,
    sys_health_normal = 1,
    sys_health_warning = 2,
    sys_health_critical = 3,

    // est.env.wind.status
    wind_status_unknown = 0,
    wind_status_available = 1,

    // est.env.eng.status
    eng_status_idle = 0,
    eng_status_ok = 1,
    eng_status_warning = 2,
    eng_status_failure = 3,


    // cmd.nav.proc.mode
    proc_mode_EMG = 0,
    proc_mode_RPV = 1,
    proc_mode_UAV = 2,
    proc_mode_WPT = 3,
    proc_mode_STBY = 4,
    proc_mode_TAXI = 5,
    proc_mode_TAKEOFF = 6,
    proc_mode_LANDING = 7,

    // cmd.nav.proc.action
    proc_action_idle = 0,
    proc_action_next = 1,
    proc_action_reset = 2,
    proc_action_inc = 3,
    proc_action_dec = 4,

    // cmd.nav.reg.att
    reg_att_off = 0,
    reg_att_on = 1,

    // cmd.nav.reg.pos
    reg_pos_off = 0,
    reg_pos_hdg = 1,
    reg_pos_direct = 2,
    reg_pos_track = 3,
    reg_pos_loiter = 4,
    reg_pos_hover = 5,

    // cmd.nav.reg.spd
    reg_spd_off = 0,
    reg_spd_on = 1,

    // cmd.nav.reg.alt
    reg_alt_off = 0,
    reg_alt_on = 1,
    reg_alt_rate = 2,

    // cmd.nav.reg.eng
    reg_eng_off = 0,
    reg_eng_on = 1,

    // cmd.nav.reg.yaw
    reg_yaw_off = 0,
    reg_yaw_hdg = 1,
    reg_yaw_slip = 2,
    reg_yaw_taxi = 3,
    reg_yaw_track = 4,

    // cmd.nav.reg.str
    reg_str_off = 0,
    reg_str_on = 1,

    // cmd.nav.reg.taxi
    reg_taxi_off = 0,
    reg_taxi_on = 1,

    // cmd.nav.reg.brk
    reg_brk_off = 0,
    reg_brk_on = 1,

    // cmd.nav.reg.flaps
    reg_flaps_off = 0,
    reg_flaps_on = 1,

    // cmd.nav.reg.airbrk
    reg_airbrk_off = 0,
    reg_airbrk_on = 1,

    // cmd.nav.ahrs.inair
    ahrs_inair_no = 0,
    ahrs_inair_yes = 1,

    // cmd.nav.ahrs.nogps
    ahrs_nogps_no = 0,
    ahrs_nogps_yes = 1,

    // cmd.nav.ahrs.nomag
    ahrs_nomag_no = 0,
    ahrs_nomag_yes = 1,

    // cmd.nav.ahrs.hsrc
    ahrs_hsrc_baro = 0,
    ahrs_hsrc_gps = 1,
    ahrs_hsrc_range = 2,
    ahrs_hsrc_vision = 3,

    // cmd.nav.ahrs.hagl
    ahrs_hagl_no = 0,
    ahrs_hagl_yes = 1,

    // cmd.nav.eng.mode
    eng_mode_auto = 0,
    eng_mode_start = 1,
    eng_mode_spin = 2,

    // cmd.nav.eng.cut
    eng_cut_off = 0,
    eng_cut_on = 1,

    // cmd.nav.eng.ovr
    eng_ovr_off = 0,
    eng_ovr_on = 1,

    // cmd.nav.rc.ovr
    rc_ovr_off = 0,
    rc_ovr_on = 1,

    // cmd.nav.cam.range
    cam_range_off = 0,
    cam_range_on = 1,

    // cmd.nav.cam.mode
    cam_mode_off = 0,
    cam_mode_single = 1,
    cam_mode_distance = 2,
    cam_mode_time = 3,

    // cmd.nav.cam.pf
    cam_pf_off = 0,
    cam_pf_on = 1,

    // cmd.nav.cam.nir
    cam_nir_off = 0,
    cam_nir_on = 1,

    // cmd.nav.cam.fm
    cam_fm_auto = 0,
    cam_fm_infinity = 1,

    // cmd.nav.cam.ft
    cam_ft_auto = 0,
    cam_ft_manual = 1,

    // cmd.nav.gimbal.mode
    gimbal_mode_off = 0,
    gimbal_mode_stab = 1,
    gimbal_mode_pos = 2,
    gimbal_mode_speed = 3,
    gimbal_mode_target = 4,
    gimbal_mode_fixed = 5,
    gimbal_mode_track = 6,

    // cmd.nav.ats.mode
    ats_mode_off = 0,
    ats_mode_track = 1,
    ats_mode_manual = 2,
    ats_mode_search = 3,

    // cmd.nav.turret.mode
    turret_mode_off = 0,
    turret_mode_fixed = 1,
    turret_mode_stab = 2,
    turret_mode_position = 3,
    turret_mode_speed = 4,


} constants_t;

// tree
namespace sns
{
    namespace nav
    {
        namespace gyro
        {
            enum { src = 0x1 };
            enum { cnt = 0x2 };
            enum { temp = 0x3 };
            enum { clip = 0x4 };
            enum { vib = 0x5 };
            enum { coning = 0x6 };
        };
        namespace acc
        {
            enum { src = 0x11 };
            enum { cnt = 0x12 };
            enum { temp = 0x13 };
            enum { clip = 0x14 };
            enum { vib = 0x15 };
        };
        namespace mag
        {
            enum { src = 0x21 };
            enum { cnt = 0x22 };
            enum { temp = 0x23 };
            enum { vib = 0x24 };
            enum { norm = 0x25 };
            enum { decl = 0x26 };
        };
        namespace gps
        {
            enum { src = 0x31 };
            enum { cnt = 0x32 };
            enum { fix = 0x33 };
            enum { emi = 0x34 };
            enum { hacc = 0x35 };
            enum { vacc = 0x36 };
            enum { sacc = 0x37 };
            enum { pdop = 0x38 };
            enum { sv = 0x39 };
            enum { su = 0x3a };
            enum { temp = 0x3b };
            enum { hmsl = 0x3c };
        };
        namespace baro
        {
            enum { src = 0x41 };
            enum { cnt = 0x42 };
            enum { status = 0x43 };
            enum { mbar = 0x44 };
            enum { temp = 0x45 };
        };
        namespace pitot
        {
            enum { src = 0x51 };
            enum { cnt = 0x52 };
            enum { valid = 0x53 };
            enum { status = 0x54 };
            enum { airspeed = 0x55 };
            enum { acc = 0x56 };
            enum { temp = 0x57 };
            enum { raw = 0x58 };
        };
        namespace agl
        {
            enum { src = 0x61 };
            enum { status = 0x62 };
            enum { laser = 0x63 };
            enum { radio = 0x64 };
            enum { sonic = 0x65 };
            enum { ground = 0x66 };
        };
        namespace air
        {
            enum { slip = 0x71 };
            enum { aoa = 0x72 };
            enum { temp = 0x73 };
            enum { buo = 0x74 };
        };
        namespace rtk
        {
            enum { roll = 0x81 };
            enum { pitch = 0x82 };
            enum { yaw = 0x83 };
        };
        namespace las
        {
            enum { status = 0x91 };
            enum { dx = 0x92 };
            enum { dy = 0x93 };
            enum { dz = 0x94 };
            enum { vx = 0x95 };
            enum { vy = 0x96 };
            enum { vz = 0x97 };
        };
        namespace pfm
        {
            enum { lat = 0xa1 };
            enum { lon = 0xa2 };
            enum { hmsl = 0xa3 };
            enum { vn = 0xa4 };
            enum { ve = 0xa5 };
            enum { vd = 0xa6 };
            enum { roll = 0xa7 };
            enum { pitch = 0xa8 };
            enum { yaw = 0xa9 };
        };
        namespace vps
        {
            enum { vx = 0xb1 };
            enum { vy = 0xb2 };
            enum { vz = 0xb3 };
            enum { dx = 0xb4 };
            enum { dy = 0xb5 };
            enum { dz = 0xb6 };
            enum { roll = 0xb7 };
            enum { pitch = 0xb8 };
            enum { yaw = 0xb9 };
            enum { lat = 0xba };
            enum { lon = 0xbb };
            enum { hmsl = 0xbc };
            enum { altitude = 0xbd };
        };
        namespace tcas
        {
            enum { dist = 0xc1 };
            enum { hdg = 0xc2 };
            enum { elv = 0xc3 };
            enum { vel = 0xc4 };
        };
    };
    namespace env
    {
        namespace eng
        {
            enum { rpm = 0x101 };
            enum { torque = 0x102 };
            enum { temp = 0x103 };
            enum { ot = 0x104 };
            enum { egt = 0x105 };
            enum { egtd = 0x106 };
            enum { op = 0x107 };
            enum { map = 0x108 };
            enum { iap = 0x109 };
            enum { voltage = 0x10a };
            enum { current = 0x10b };
            enum { health = 0x10c };
            enum { tc = 0x10d };
        };
        namespace gbox
        {
            enum { status = 0x111 };
            enum { rpm = 0x112 };
            enum { temp = 0x113 };
            enum { clutch = 0x114 };
        };
        namespace prop
        {
            enum { status = 0x121 };
            enum { rpm = 0x122 };
            enum { pitch = 0x123 };
            enum { thrust = 0x124 };
        };
        namespace gen
        {
            enum { status = 0x131 };
            enum { rpm = 0x132 };
            enum { voltage = 0x133 };
            enum { current = 0x134 };
            enum { temp = 0x135 };
        };
        namespace fuel
        {
            enum { level = 0x141 };
            enum { rate = 0x142 };
            enum { temp = 0x143 };
            enum { ps = 0x144 };
        };
        namespace bat
        {
            enum { status = 0x151 };
            enum { voltage = 0x152 };
            enum { current = 0x153 };
            enum { capacity = 0x154 };
            enum { temp = 0x155 };
        };
        namespace pwr
        {
            enum { status = 0x161 };
            enum { vsys = 0x162 };
            enum { isys = 0x163 };
            enum { vsrv = 0x164 };
            enum { isrv = 0x165 };
            enum { vpld = 0x166 };
            enum { ipld = 0x167 };
        };
        namespace com
        {
            enum { status = 0x171 };
            enum { rss = 0x172 };
            enum { snr = 0x173 };
            enum { temp = 0x174 };
            enum { voltage = 0x175 };
            enum { current = 0x176 };
            enum { hdg = 0x177 };
            enum { dme = 0x178 };
            enum { roll = 0x179 };
            enum { pitch = 0x17a };
            enum { yaw = 0x17b };
        };
        namespace aux
        {
            enum { srv = 0x181 };
            enum { rt = 0x182 };
            enum { gear = 0x183 };
            enum { fgear = 0x184 };
        };
        namespace ers
        {
            enum { status = 0x191 };
            enum { block = 0x192 };
        };
        namespace srv
        {
            enum { pos = 0x1a1 };
            enum { dpos = 0x1a2 };
            enum { power = 0x1a3 };
        };
        namespace cam
        {
            enum { roll = 0x1b1 };
            enum { pitch = 0x1b2 };
            enum { yaw = 0x1b3 };
            enum { droll = 0x1b4 };
            enum { dpitch = 0x1b5 };
            enum { dyaw = 0x1b6 };
            enum { fov = 0x1b7 };
            enum { range = 0x1b8 };
        };
        namespace turret
        {
            enum { roll = 0x1c1 };
            enum { pitch = 0x1c2 };
            enum { yaw = 0x1c3 };
            enum { status = 0x1c4 };
            enum { capacity = 0x1c5 };
        };
    };
};
namespace ctr
{
    namespace nav
    {
        namespace att
        {
            enum { ail = 0x201 };
            enum { elv = 0x202 };
            enum { rud = 0x203 };
        };
        namespace eng
        {
            enum { thr = 0x211 };
            enum { prop = 0x212 };
            enum { choke = 0x213 };
            enum { tune = 0x214 };
            enum { tvec = 0x215 };
            enum { starter = 0x216 };
            enum { ign1 = 0x217 };
            enum { ign2 = 0x218 };
            enum { fpump = 0x219 };
        };
        namespace wing
        {
            enum { flaps = 0x221 };
            enum { airbrk = 0x222 };
            enum { slats = 0x223 };
            enum { sweep = 0x224 };
            enum { buo = 0x225 };
        };
        namespace str
        {
            enum { brake = 0x231 };
            enum { gear = 0x232 };
            enum { rud = 0x233 };
        };
    };
    namespace env
    {
        namespace pwr
        {
            enum { ap = 0x301 };
            enum { servo = 0x302 };
            enum { ignition = 0x303 };
            enum { payload = 0x304 };
            enum { agl = 0x305 };
            enum { xpdr = 0x306 };
            enum { satcom = 0x307 };
            enum { rfamp = 0x308 };
            enum { ice = 0x309 };
            enum { las = 0x30a };
        };
        namespace aux
        {
            enum { horn = 0x311 };
        };
        namespace ers
        {
            enum { launch = 0x321 };
            enum { rel = 0x322 };
        };
        namespace light
        {
            enum { nav = 0x331 };
            enum { taxi = 0x332 };
            enum { beacon = 0x333 };
            enum { landing = 0x334 };
            enum { strobe = 0x335 };
        };
        namespace door
        {
            enum { main = 0x341 };
            enum { drop = 0x342 };
        };
        namespace cam
        {
            enum { roll = 0x351 };
            enum { pitch = 0x352 };
            enum { yaw = 0x353 };
            enum { rec = 0x354 };
            enum { shot = 0x355 };
            enum { arm = 0x356 };
            enum { zin = 0x357 };
            enum { zout = 0x358 };
            enum { aux = 0x359 };
        };
        namespace ats
        {
            enum { roll = 0x361 };
            enum { pitch = 0x362 };
            enum { yaw = 0x363 };
        };
        namespace turret
        {
            enum { roll = 0x371 };
            enum { pitch = 0x372 };
            enum { yaw = 0x373 };
            enum { op = 0x374 };
        };
        namespace usr
        {
            enum { u1 = 0x381 };
            enum { u2 = 0x382 };
            enum { u3 = 0x383 };
            enum { u4 = 0x384 };
            enum { u5 = 0x385 };
            enum { u6 = 0x386 };
            enum { u7 = 0x387 };
            enum { u8 = 0x388 };
            enum { ub1 = 0x389 };
            enum { ub2 = 0x38a };
            enum { ub3 = 0x38b };
            enum { ub4 = 0x38c };
            enum { ub5 = 0x38d };
            enum { ub6 = 0x38e };
            enum { ub7 = 0x38f };
        };
        namespace scr
        {
            enum { s1 = 0x391 };
            enum { s2 = 0x392 };
            enum { s3 = 0x393 };
            enum { s4 = 0x394 };
            enum { s5 = 0x395 };
            enum { s6 = 0x396 };
            enum { s7 = 0x397 };
            enum { s8 = 0x398 };
            enum { s9 = 0x399 };
            enum { s10 = 0x39a };
            enum { s11 = 0x39b };
            enum { s12 = 0x39c };
            enum { s13 = 0x39d };
            enum { s14 = 0x39e };
            enum { s15 = 0x39f };
        };
    };
};
namespace est
{
    namespace nav
    {
        namespace att
        {
            enum { status = 0x401 };
            enum { valid = 0x402 };
            enum { roll = 0x403 };
            enum { pitch = 0x404 };
            enum { yaw = 0x405 };
            enum { mag = 0x406 };
            enum { rest = 0x407 };
        };
        namespace pos
        {
            enum { status = 0x411 };
            enum { valid = 0x412 };
            enum { lat = 0x413 };
            enum { lon = 0x414 };
            enum { hmsl = 0x415 };
            enum { agl = 0x416 };
            enum { bearing = 0x417 };
            enum { speed = 0x418 };
            enum { altitude = 0x419 };
            enum { vspeed = 0x41a };
            enum { hsrc = 0x41b };
        };
        namespace gyro
        {
            enum { valid = 0x421 };
            enum { x = 0x422 };
            enum { y = 0x423 };
            enum { z = 0x424 };
            enum { ax = 0x425 };
            enum { ay = 0x426 };
            enum { az = 0x427 };
            enum { turn = 0x428 };
        };
        namespace acc
        {
            enum { valid = 0x431 };
            enum { x = 0x432 };
            enum { y = 0x433 };
            enum { z = 0x434 };
        };
        namespace lpos
        {
            enum { status = 0x441 };
            enum { ax = 0x442 };
            enum { ay = 0x443 };
            enum { az = 0x444 };
            enum { vx = 0x445 };
            enum { vy = 0x446 };
            enum { vz = 0x447 };
            enum { n = 0x448 };
            enum { e = 0x449 };
            enum { d = 0x44a };
        };
        namespace ref
        {
            enum { status = 0x451 };
            enum { lat = 0x452 };
            enum { lon = 0x453 };
            enum { hmsl = 0x454 };
        };
        namespace air
        {
            enum { airspeed = 0x461 };
            enum { slip = 0x462 };
            enum { aoa = 0x463 };
            enum { ld = 0x464 };
            enum { vse = 0x465 };
            enum { rho = 0x466 };
            enum { ktas = 0x467 };
            enum { keas = 0x468 };
            enum { stab = 0x469 };
            enum { stall = 0x46a };
        };
        namespace wpt
        {
            enum { status = 0x471 };
            enum { eta = 0x472 };
            enum { dist = 0x473 };
            enum { hdg = 0x474 };
            enum { xtrack = 0x475 };
            enum { delta = 0x476 };
            enum { thdg = 0x477 };
        };
    };
    namespace env
    {
        namespace sys
        {
            enum { mode = 0x501 };
            enum { health = 0x502 };
            enum { time = 0x503 };
            enum { uptime = 0x504 };
            enum { fuel = 0x505 };
            enum { weight = 0x506 };
            enum { ttl = 0x507 };
            enum { range = 0x508 };
            enum { corr = 0x509 };
        };
        namespace wind
        {
            enum { status = 0x511 };
            enum { speed = 0x512 };
            enum { heading = 0x513 };
        };
        namespace eng
        {
            enum { status = 0x521 };
            enum { rpm = 0x522 };
            enum { drpm = 0x523 };
        };
        namespace ats
        {
            enum { roll = 0x531 };
            enum { pitch = 0x532 };
            enum { yaw = 0x533 };
        };
        namespace cam
        {
            enum { roll = 0x541 };
            enum { pitch = 0x542 };
            enum { yaw = 0x543 };
            enum { lat = 0x544 };
            enum { lon = 0x545 };
            enum { hmsl = 0x546 };
        };
        namespace turret
        {
            enum { roll = 0x551 };
            enum { pitch = 0x552 };
            enum { yaw = 0x553 };
            enum { lat = 0x554 };
            enum { lon = 0x555 };
            enum { hmsl = 0x556 };
        };
        namespace usr
        {
            enum { u1 = 0x561 };
            enum { u2 = 0x562 };
            enum { u3 = 0x563 };
            enum { u4 = 0x564 };
            enum { u5 = 0x565 };
            enum { u6 = 0x566 };
            enum { u7 = 0x567 };
            enum { u8 = 0x568 };
            enum { ub1 = 0x569 };
            enum { ub2 = 0x56a };
            enum { ub3 = 0x56b };
            enum { ub4 = 0x56c };
            enum { ub5 = 0x56d };
            enum { ub6 = 0x56e };
            enum { ub7 = 0x56f };
        };
        namespace haps
        {
            enum { shape = 0x571 };
            enum { cshape = 0x572 };
            enum { roll = 0x573 };
            enum { roll1 = 0x574 };
            enum { roll2 = 0x575 };
            enum { pitch1 = 0x576 };
            enum { pitch2 = 0x577 };
            enum { cpitch1 = 0x578 };
            enum { cpitch2 = 0x579 };
            enum { spd1 = 0x57a };
            enum { spd2 = 0x57b };
            enum { ail1 = 0x57c };
            enum { ail2 = 0x57d };
        };
    };
};
namespace cmd
{
    namespace nav
    {
        namespace proc
        {
            enum { mode = 0x601 };
            enum { stage = 0x602 };
            enum { wp = 0x603 };
            enum { rw = 0x604 };
            enum { pi = 0x605 };
            enum { action = 0x606 };
            enum { adj = 0x607 };
            enum { loops = 0x608 };
            enum { timeout = 0x609 };
        };
        namespace reg
        {
            enum { att = 0x611 };
            enum { pos = 0x612 };
            enum { spd = 0x613 };
            enum { alt = 0x614 };
            enum { eng = 0x615 };
            enum { yaw = 0x616 };
            enum { str = 0x617 };
            enum { taxi = 0x618 };
            enum { brk = 0x619 };
            enum { flaps = 0x61a };
            enum { airbrk = 0x61b };
        };
        namespace ahrs
        {
            enum { inair = 0x621 };
            enum { nogps = 0x622 };
            enum { nomag = 0x623 };
            enum { hsrc = 0x624 };
            enum { hagl = 0x625 };
        };
        namespace att
        {
            enum { roll = 0x631 };
            enum { pitch = 0x632 };
            enum { yaw = 0x633 };
            enum { slip = 0x634 };
        };
        namespace pos
        {
            enum { lat = 0x641 };
            enum { lon = 0x642 };
            enum { hmsl = 0x643 };
            enum { bearing = 0x644 };
            enum { airspeed = 0x645 };
            enum { altitude = 0x646 };
            enum { vspeed = 0x647 };
            enum { tecs = 0x648 };
            enum { radius = 0x649 };
        };
        namespace eng
        {
            enum { mode = 0x651 };
            enum { rpm = 0x652 };
            enum { cut = 0x653 };
            enum { ovr = 0x654 };
        };
        namespace rc
        {
            enum { ovr = 0x661 };
            enum { roll = 0x662 };
            enum { pitch = 0x663 };
            enum { thr = 0x664 };
            enum { yaw = 0x665 };
        };
        namespace cam
        {
            enum { zoom = 0x671 };
            enum { focus = 0x672 };
            enum { ch = 0x673 };
            enum { range = 0x674 };
            enum { mode = 0x675 };
            enum { dshot = 0x676 };
            enum { tshot = 0x677 };
            enum { pf = 0x678 };
            enum { nir = 0x679 };
            enum { fm = 0x67a };
            enum { ft = 0x67b };
        };
        namespace gimbal
        {
            enum { mode = 0x681 };
            enum { roll = 0x682 };
            enum { pitch = 0x683 };
            enum { yaw = 0x684 };
            enum { broll = 0x685 };
            enum { bpitch = 0x686 };
            enum { byaw = 0x687 };
            enum { lat = 0x688 };
            enum { lon = 0x689 };
            enum { hmsl = 0x68a };
        };
        namespace ats
        {
            enum { mode = 0x691 };
            enum { roll = 0x692 };
            enum { pitch = 0x693 };
            enum { yaw = 0x694 };
            enum { p = 0x695 };
            enum { q = 0x696 };
            enum { r = 0x697 };
        };
        namespace turret
        {
            enum { mode = 0x6a1 };
            enum { roll = 0x6a2 };
            enum { pitch = 0x6a3 };
            enum { yaw = 0x6a4 };
            enum { p = 0x6a5 };
            enum { q = 0x6a6 };
            enum { r = 0x6a7 };
            enum { broll = 0x6a8 };
            enum { bipitch = 0x6a9 };
            enum { byaw = 0x6aa };
        };
    };
    namespace env
    {
        namespace vehicle
        {
            enum { ident = 0x701 };
            enum { downlink = 0x702 };
            enum { uplink = 0x703 };
            enum { telemetry = 0x704 };
            enum { xpdr = 0x705 };
        };
        namespace telemetry
        {
            enum { data = 0x711 };
            enum { format = 0x712 };
            enum { xpdr = 0x713 };
        };
        namespace stream
        {
            enum { vcp = 0x721 };
            enum { calib = 0x722 };
            enum { pld = 0x723 };
        };
        namespace sim
        {
            enum { sns = 0x731 };
            enum { ctr = 0x732 };
            enum { cfg = 0x733 };
            enum { display = 0x734 };
        };
        namespace script
        {
            enum { vmexec = 0x741 };
            enum { jsexec = 0x742 };
        };
        namespace aux
        {
            enum { gcs = 0x751 };
            enum { pld = 0x752 };
            enum { hid = 0x753 };
        };
        namespace redundancy
        {
            enum { alive = 0x761 };
        };
        namespace formation
        {
            enum { haps = 0x771 };
            enum { left = 0x772 };
            enum { right = 0x773 };
            enum { center = 0x774 };
        };
        namespace nmt
        {
            enum { search = 0x7f1 };
            enum { ident = 0x7f2 };
            enum { file = 0x7f3 };
            enum { reboot = 0x7f4 };
            enum { msg = 0x7f5 };
            enum { upd = 0x7f6 };
            enum { mod = 0x7f7 };
            enum { usr = 0x7f8 };
            enum { tree = 0x7f9 };
            enum { debug = 0x7fa };
        };
    };
};

}; // namespace

