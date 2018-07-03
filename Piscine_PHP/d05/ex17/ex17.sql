SELECT COUNT(id_sub) AS 'nb_susc', 
	TRUNCATE(AVG(price), 0) AS 'av_susc', 
	SUM(duration_sub % 42) AS 'ft'
	FROM subscription;

