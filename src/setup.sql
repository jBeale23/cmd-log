CREATE TABLE IF NOT EXISTS users (
	user_name TEXT NOT NULL,
	host_name TEXT NOT NULL,
	PRIMARY KEY (user_name, host_name)
);

CREATE TABLE IF NOT EXISTS command_log (
	id INTEGER PRIMARY KEY,
	user_name TEXT NOT NULL,
	host_name TEXT NOT NULL,
	datetime TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
	command TEXT NOT NULL
);

CREATE TABLE IF NOT EXISTS configuration (
	key TEXT NOT NULL,
	value TEXT NOT NULL,
	PRIMARY KEY(key, value)
);

CREATE UNIQUE INDEX IF NOT EXISTS unique_number_entries
ON configuration(key)
WHERE key LIKE '%.number_entries_displayed';
