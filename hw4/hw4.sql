create table rankings (id int primary key, name varchar(256), state varchar(10), public int, mathSAT int, verbalSAT int, combinedSAT int, ACT int, firstQMathSAT int, thirdQMathSAT int, firstQVerbalSAT int, thirdQVerbalSAT int, firstQACT int, thirdQACT int, applications int, accepted int, enrolled int, PercentInTop10PercentofHS float, PercentInTop25PercentofHS float, fulltimeUndergrads int, parttimeUndergrads int, instateTuition int, outofstateTuition int, roomAndBoardCosts int, RoomCosts int, BoardCosts int, additionalFees int, bookCosts int, personalSpending int, PctFacultyWithPhD float, PctFacultyWithTerminalDeg float, StudentFacultyRatio float, PctAlumniWhoDonate float, InstructionalSpendingPerStudent float, GradRate float);

create table financials (id int primary key, name varchar(256), state varchar(10), type varchar(10), fullprofsalary float, associateprofsalary float, assistantprofsalary float, aveSalary float, fullprofcompensation float, associateprofcompensation float, assistantprofcompensation float, avecompensation float, numFullProf int, numAssociateProf int, numAssistantProf int, numInstructors int, numFaculty int);

create table students (id int primary key, name varchar(256), school int);

copy rankings from '$HOME/fa12/hw4/usnews.data' delimiters ',' with NULL '*';
copy financials from '$HOME/fa12/hw4/aaup.data' delimiters ',' with NULL '*';
copy students from '$HOME/fa12/hw4/students.dat' delimiters ',';

create index gradrate_idx on rankings(gradrate);

set enable_bitmapscan to off;
