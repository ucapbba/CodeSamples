#run before program execution
.open DropDown.db
CREATE TABLE IF NOT EXISTS MyPets (name TEXT ,pettype TEXT); 
insert into MyPets (name,pettype) values ('bob','dog'); 
insert into MyPets (name,pettype) values ('simba','cat'); 