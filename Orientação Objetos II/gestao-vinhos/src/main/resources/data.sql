insert into role(id, name) values(1, 'Admin');
insert into role(id, name) values(2, 'User');
insert into user(id, username, password, name) values (1, 'admin@admin.com', 'admin', 'Administrator');
insert into user_role(user_id, role_id) values(1, 1);
insert into tipo_vinho(id, descricao) values (1, 'Seco');
insert into tipo_vinho(id, descricao) values (2, 'Suave');