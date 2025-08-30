
difference() {

    translate([-125,-105,0])
        import("restrictor.3mf");
        
    union() {
        translate([0, 24, 0])
            linear_extrude(1)    
                square([14, 16], center = true);               
        translate([24, 0, 0])
            linear_extrude(1)    
                square([16, 14], center = true);
                               
        translate([0, -24, 0])
            linear_extrude(1)    
                square([14, 16], center = true);               
        translate([-24, 0, 0])
            linear_extrude(1)    
                square([16, 14], center = true);
                
        translate([0, 28, 0])
            linear_extrude(5)    
                square([30, 2], center = true); 
        translate([0, -28, 0])
            linear_extrude(5)    
                square([30, 2], center = true);  
        translate([28, 0, 0])
            linear_extrude(5)    
                square([2, 30], center = true);  
        translate([-28, 0, 0])
            linear_extrude(5)    
                square([2, 30], center = true);   
    }
}