#run before program execution
sqlite3.exe sample.db
CREATE TABLE IF NOT EXISTS sample_table (	value1 REAL,	value2 REAL); 

#example insert
insert into sample_table (value1,value2) values (3,3); 