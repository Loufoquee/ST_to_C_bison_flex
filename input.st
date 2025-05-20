VAR
    inputString : STRING := '123 "Hello, World!" 456';
    currentChar : STRING;
    index : INT := 1;
    token : STRING;
    result : STRING;
END_VAR

WHILE index <= LEN(inputString) DO
    currentChar := MID(inputString, index, 1);

    IF currentChar = ' ' OR currentChar = '\n' OR currentChar = '\t' THEN
        index := index + 1;

    ELSIF currentChar = '"' THEN
        token := '';
        index := index + 1;
        WHILE index <= LEN(inputString) AND NOT (MID(inputString, index, 1) = '"') DO
            token := CONCAT(token, MID(inputString, index, 1));
            index := index + 1;
        END_WHILE;
        IF index <= LEN(inputString) THEN
            index := index + 1;
            result := CONCAT('String: ', token);
        END_IF;

    ELSIF currentChar >= '0' AND currentChar <= '9' THEN
        token := '';
        WHILE index <= LEN(inputString) AND (MID(inputString, index, 1) >= '0' AND MID(inputString, index, 1) <= '9') DO
            token := CONCAT(token, MID(inputString, index, 1));
            index := index + 1;
        END_WHILE;
        result := CONCAT('Integer: ', token);

    ELSE
        result := CONCAT('Unknown character: ', currentChar);
        index := index + 1;
    END_IF;
    TRACE(result);
    IF result <> '' THEN
        result := '';
    END_IF;
END_WHILE;
