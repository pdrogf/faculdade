insert into role(id, name) values(1, 'ROLE_ADMIN');
insert into role(id, name) values(2, 'ROLE_USER');
insert into user(id, username, password, name) values (1, 'admin', '$2a$10$w2Z0fNwbt3PBh28xNNbRxenps0kwgx786mD6zHKjYVyR.', 'Administrator');
insert into user_role(user_id, role_id) values(1, 1);