package com.hard;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;

public class WordBreak2 {
    public List<String> wordBreak(String s, List<String> wordDict) {
        return wordHelper(s, wordDict, new HashMap<String, List<String>>());
        
    }

	private List<String> wordHelper(String s, List<String> wordDict, Map<String, List<String>> cache) {
		if(cache.containsKey(s))
			return cache.get(s);
		List<String> res= new ArrayList<String>();
		if(s.length()==0) 
		{
			res.add("");
			return res;
		}
		for(String word:wordDict)
		{
			//Check if the word starts with the dictionary word
			if(s.startsWith(word))
			{
				//Now we need to find all the subsets of in the String from the dict
				//and add them to a List
				List<String> subStr= wordHelper(s.substring(word.length()), wordDict, cache);
				//Now we have all the subsets, we will now start making our results
				for(String subs: subStr)
				{
					String space= subs.isEmpty()? "":" ";
					res.add(word+space+subs);
				}
			}
		}
		cache.put(s, res);
		return res;
	}
}
