-- Dissector for doha trdp
-- author: Salvatore Muoio
-- company HaslerRail

-- declare the protocol
trdp_proto = Proto("trdp", "UDP Protocol (lua dissector)")

local Source_Device_Code = {
    [0]    = "10.128.64.59",
    [2]    = "10.128.64.21",
    [3]    = "10.128.64.41",
    [4]    = "10.128.64.42",
    [5]    = "10.128.64.44",
    [6]    = "10.128.64.45",
	[7]    = "10.128.64.25",
	[8]    = "10.128.64.26"
};

local Name_Device = {
    [0]    = "Event Recorder",
    [2]    = "Train Controller",
    [3]    = "TCU 1",
    [4]    = "TCU 2",
    [5]    = "BCU 1",
    [6]    = "BCU 2",
	[7]    = "Cab Interface Unit(System 1)",
	[8]    = "Cab Interface Unit(System 2)"
};

local Process_request_fiels = {
    [0]    = "Destination Device ID",
};

local sequence_counter = ProtoField.uint32("trdp.seq", "Sequence Counter", base.HEX)
local protocol_version = ProtoField.uint16("trdp.seq", "Protocol Version", base.HEX)
local msg_type         = ProtoField.uint16("trdp.seq", "Message Type", base.HEX, { [0x5064] = 'Process Data', [0x5072] = 'Process request', [0x4D72] = 'MDr:Message Data request', [0x4D70] = 'MDp:Message Data reply', [0x4D65] = 'MDe:Message Data error'})
local comid            = ProtoField.uint32("trdp.seq", "ComId", base.HEX)
local topocount        = ProtoField.uint32("trdp.seq", "Topo Count", base.HEX)
local datasetlength    = ProtoField.uint32("trdp.seq", "Dataset Length", base.HEX)
local reserved_1       = ProtoField.uint32("trdp.seq", "Reserved", base.HEX)
local reserved_2       = ProtoField.uint32("trdp.seq", "Reserved", base.HEX)
local replyipaddress   = ProtoField.uint32("trdp.seq", "ReplyIpAddress", base.HEX)
local dataset          = ProtoField.uint8( "trdp.seq", "Dataset.data", base.HEX)
local fcs              = ProtoField.uint8("trdp.seq", "FCS", base.HEX)
local pr_header        = ProtoField.uint8("trdp.seq", "Destination Device ID", base.HEX)
local pr_year          = ProtoField.uint8("trdp.seq", "Year", base.HEX)
local pr_month         = ProtoField.uint8("trdp.seq", "Month", base.HEX)
local pr_day           = ProtoField.uint8("trdp.seq", "Day", base.HEX)
local pr_hour          = ProtoField.uint8("trdp.seq", "Hour", base.HEX)
local pr_minute        = ProtoField.uint8("trdp.seq", "Minute", base.HEX)
local pr_second        = ProtoField.uint8("trdp.seq", "Second", base.HEX)
--local device           = ProtoField.uint32("trdp.seq", "Local device", base.HEX)


trdp_proto.fields = { sequence_counter, protocol_version, msg_type, comid, topocount, datasetlength, reserved_1, reserved_2, replyipaddress, dataset, fcs, pr_header, pr_year, pr_day, pr_month, pr_hour,
                      pr_minute, pr_second}

function trdp_proto.dissector(buffer, pinfo, tree)
local subtree = tree:add (trdp_proto, buffer(0))
local source = tostring(pinfo.src)
pinfo.cols.protocol = trdp_proto.name
-- create the tree
-- create variables dissector
-- used the technical specification from Hitachi Ethernet Communication Interface Specification 
   --pinfo.cols.info:append(source)
   for i = 0, 9-1 do
	if(source == Source_Device_Code[i]) then
        subtree:add("Device Source: " .. Name_Device[i] )
	end
   end
   subtree:add (sequence_counter, buffer(0,4))
   subtree:add (protocol_version, buffer(4,2))
   subtree:add (msg_type,         buffer(6,2))
   subtree:add (comid,            buffer(8,4))
   subtree:add (topocount,        buffer(12,4))
   subtree:add (datasetlength,    buffer(16,4))
   subtree:add (reserved_1,       buffer(20,4))
   subtree:add (reserved_2,       buffer(24,4))
   subtree:add (replyipaddress,   buffer(28,4))
   msgtype = buffer(6,2):uint()
   len = buffer(16,4):uint()
   for i = 0, len-1 do
	if(msgtype == 0x5072) then
		if(i == 0) then
			subtree:add(pr_header, buffer(32+i, 1))
		elseif(i == 20) then
			subtree:add(pr_year, buffer(32+i, 1))
		elseif(i == 21) then
			subtree:add(pr_month, buffer(32+i, 1))
		elseif(i == 22) then
			subtree:add(pr_day, buffer(32+i, 1))
		elseif(i == 23) then
			subtree:add(pr_hour, buffer(32+i, 1))
		elseif(i == 24) then
			subtree:add(pr_minute, buffer(32+i, 1))
		elseif(i == 25) then
			subtree:add(pr_second, buffer(32+i, 1))
		else 
			subtree:add(dataset, buffer(32+i, 1))
		end
	elseif(msgtype == 0x5064) then 
		subtree:add(dataset, buffer(32+i, 1))
	end
   end
   subtree:add(fcs, buffer(32+len, 4))
end

local tcp_port = DissectorTable.get("udp.port")
tcp_port:add(52101,trdp_proto)
tcp_port:add(51110,trdp_proto)
tcp_port:add(51120,trdp_proto)
