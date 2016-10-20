<?php
    $dictionary = [];
    
    function load($filePath = "./dictionaries/large")
    {
        global $dictionary;
        
        if (!empty($filePath)
            && file_exists($filePath)
            && is_readable($filePath))
        {
            $lines = file($filePath, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
            foreach ($lines as $line)
            {
                $dictionary[$line] = true;
            }
        }
    }
    
    function check($key)
    {
        global $dictionary;
        
        return !empty($key)
            && isset($dictionary[$key]);
    }
?>