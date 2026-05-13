CREATE TABLE IF NOT EXISTS users (
	user_name TEXT NOT NULL,
	host_name TEXT NOT NULL,
	PRIMARY KEY (user_name, host_name)
);

CREATE TABLE IF NOT EXISTS command_log (
	user_name TEXT NOT NULL,
	host_name TEXT NOT NULL,
	datetime TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
	command TEXT NOT NULL,
	PRIMARY KEY (user_name, host_name)
);

CREATE TABLE IF NOT EXISTS configuration (
	ignore_commands TEXT NOT NULL,
)
