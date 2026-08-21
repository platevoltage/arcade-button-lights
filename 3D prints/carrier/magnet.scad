$fn = 100; 

// color(c = "#ffff4444")
// difference () {
//     union() {   
//         rotate([0, 0, 0]) translate([0, 0, 0]) linear_extrude(height = 3.5, scale=1.1) circle(d = 22.5);
//         rotate([0, 0, 0]) translate([0, 0, -2]) linear_extrude(height = 3, scale=1.5) circle(d = 12);
//     }
//     union() {
//         rotate([0, 0, 0]) translate([0, 0, 2]) linear_extrude(height = 3) circle(d = 22.5);
//         rotate([0, 0, 0]) translate([0, 0, -1]) linear_extrude(height = 5) circle(d = 7.5);
//         rotate([0, 0, 0]) translate([0, 0, -4.2]) linear_extrude(height = 4) circle(d = 11.3);
//     }
// }


difference() {
    union() {
        rotate([0, 0, 0]) translate([0, 0, 0]) linear_extrude(height = 3.5, scale=1.1) square([23, 23], center=true);
    }
    union() {
        rotate([0, 0, 0]) translate([0, 0, 2]) linear_extrude(height = 3) square([22, 22], center=true);
        rotate([0, 0, 0]) translate([0, 0, -1]) linear_extrude(height = 5) square([7, 7], center=true);
        for (r = [0, 90, 180, 270])
            rotate([0, 0, 45 + r]) translate([0, 20, -1]) linear_extrude(height = 5, scale=.9) square([20, 20], center=true);
    }
}