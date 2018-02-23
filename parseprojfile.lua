local end_line = '\r\n'

function parse_proj_1_0(conf)
	local result = ""
	
	if not conf then print('no conf') return 'no conf' end
	
	local append = function(str) result = string.format("%s%s%s",result,str,end_line) end
	if not conf.project_name then 
		append("No project name")
	end
	if not conf.wle_version then 
		append("No wle version")
	end
	if not conf.project_version then
		append("No project version")
	end
	if not conf.base_dir then
		append("No base project directory")
	end

	local search_first = "^"..end_line
	local search_last = end_line.."$"
	result = result:gsub(search_first,""):gsub(search_last,"")
	
	return result
end

