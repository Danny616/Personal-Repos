create table Drivers
(
    DriverID           int auto_increment
        primary key,
    FirstName          varchar(50)               not null,
    LastName           varchar(50)               not null,
    DIN                varchar(20)               not null,
    Address            varchar(100)              null,
    HoursWorkedPerWeek int                       null,
    JoiningDateTime    datetime                  null,
    DateOfBirth        date                      null,
    Rating             decimal(3, 1) default 5.0 null,
    constraint DIN
        unique (DIN)
);

create table Payments
(
    PaymentID                 int auto_increment
        primary key,
    RideID                    int                             null,
    RideAmount                decimal(10, 2)                  null,
    RidePaymentDateTime       datetime                        null,
    RideTip                   decimal(10, 2)                  null,
    PaidBy                    enum ('CASH', 'CARD', 'CHEQUE') null,
    CardNumber                varchar(20)                     null,
    NameOnCard                varchar(100)                    null,
    CardExpiryDate            date                            null,
    ChequeNumber              varchar(20)                     null,
    BankNameOnCheque          varchar(100)                    null,
    AccountHolderNameOnCheque varchar(100)                    null,
    constraint payments_ibfk_1
        foreign key (RideID) references td8233_uberapp_db.Rides (RideID)
);

create index RideID
    on Payments (RideID);

create table Rides
(
    RideID            int auto_increment
        primary key,
    UserID            int                                                       null,
    DriverID          int                                                       null,
    RideStartDateTime datetime                                                  null,
    RideEndDateTime   datetime                                                  null,
    DistanceTravelled decimal(10, 2)                                            null,
    RideStars         decimal(3, 1)                                             null,
    RideStatus        enum ('INITIATED', 'ACCEPTED', 'IN TRANSIT', 'COMPLETED') null,
    constraint rides_ibfk_1
        foreign key (UserID) references td8233_uberapp_db.Users (UserID),
    constraint rides_ibfk_2
        foreign key (DriverID) references td8233_uberapp_db.Drivers (DriverID)
);

create index DriverID
    on Rides (DriverID);

create index UserID
    on Rides (UserID);

create table Users
(
    UserID        int auto_increment
        primary key,
    FirstName     varchar(50)  not null,
    LastName      varchar(50)  not null,
    ContactNumber varchar(15)  null,
    Address       varchar(100) null,
    LastLogin     datetime     null,
    EmailAddress  varchar(100) null
);


