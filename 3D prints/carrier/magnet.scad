$fn = 100; 

difference () {
    union() {   
        rotate([0, 0, 0]) translate([0, 0, 0]) linear_extrude(height = 3.5, scale=1.1) circle(d = 22.5);
        rotate([0, 0, 0]) translate([0, 0, -2]) linear_extrude(height = 3, scale=1.5) circle(d = 12);
    }
    union() {
        rotate([0, 0, 0]) translate([0, 0, 2]) linear_extrude(height = 3) circle(d = 22.5);
        rotate([0, 0, 0]) translate([0, 0, -1]) linear_extrude(height = 5) circle(d = 7.5);
        rotate([0, 0, 0]) translate([0, 0, -4.2]) linear_extrude(height = 4) circle(d = 11.3);
    }
}