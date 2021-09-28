package com.example.task1.tools;

import java.util.SortedMap;

public class Filters {
    public static SortedMap<String, String> filterPrefix(SortedMap<String, String> baseMap, String prefix) {
        if(prefix.length() > 0) {
            char nextLetter = (char) (prefix.charAt(prefix.length() - 1) + 1);
            String end = prefix.substring(0, prefix.length()-1) + nextLetter;
            return baseMap.subMap(prefix, end);
        }
        return baseMap;
    }
}
