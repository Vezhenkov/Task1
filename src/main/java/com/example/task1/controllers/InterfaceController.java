package com.example.task1.controllers;

import com.example.task1.tools.Filters;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import java.util.Map;
import java.util.SortedMap;
import java.util.TreeMap;

@Controller
public class InterfaceController {
    private static final SortedMap<String, String> users = new TreeMap<>();

    @RequestMapping(value="/user", method=RequestMethod.GET)
    public @ResponseBody CharSequence getUser(@RequestParam String num) {
        StringBuilder i = new StringBuilder();
        if (num.matches("\\+?[0-9]+")) {
            String prefix = "[";
            for(Map.Entry<String,String> entry : Filters.filterPrefix(users, num).entrySet()) {
                i.append(prefix);
                prefix = ", ";
                i.append(entry.getValue());
            }
        } else {
            return "error: wrong number";
        }

        if(i.length() == 0) { return "not found"; }
        i.append("]");
        return i;
    }

    @RequestMapping(value="/user", method=RequestMethod.POST)
    public @ResponseBody String putUser(@RequestParam Map<String,String> requestParams) {
        String user = requestParams.get("user");
        String num = requestParams.get("num");
        if (user != null && num != null){
            if (num.matches("\\+?[0-9]+")) {
                users.put(num, user);
            } else {
                return "error: wrong number";
            }
        } else {
            return "error: fields user/num were not received";
        }
        return "registered: " + user;
    }
}
