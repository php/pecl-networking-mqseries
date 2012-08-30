ADD_MQ_REASON_TXT(MQRC_NONE, "No reason to report."); /* 0 */
ADD_MQ_REASON_TXT(MQRC_APPL_FIRST, "Lowest value for an application-defined reason code returned by a data-conversion exit."); /* 900 */
ADD_MQ_REASON_TXT(MQRC_APPL_LAST, "Highest value for application-defined reason code returned by a data-conversion exit."); /* 999 */
ADD_MQ_REASON_TXT(MQRC_ALIAS_BASE_Q_TYPE_ERROR, "Alias base queue not a valid type."); /* 2001 */
ADD_MQ_REASON_TXT(MQRC_ALREADY_CONNECTED, "Application already connected."); /* 2002 */
ADD_MQ_REASON_TXT(MQRC_BACKED_OUT, "Unit of work encountered fatal error or backed out."); /* 2003 */
ADD_MQ_REASON_TXT(MQRC_BUFFER_ERROR, "Buffer parameter not valid."); /* 2004 */
ADD_MQ_REASON_TXT(MQRC_BUFFER_LENGTH_ERROR, "Buffer length parameter not valid."); /* 2005 */
ADD_MQ_REASON_TXT(MQRC_CHAR_ATTR_LENGTH_ERROR, "Length of character attributes not valid."); /* 2006 */
ADD_MQ_REASON_TXT(MQRC_CHAR_ATTRS_ERROR, "Character attributes string not valid."); /* 2007 */
ADD_MQ_REASON_TXT(MQRC_CHAR_ATTRS_TOO_SHORT, "Not enough space allowed for character attributes."); /* 2008 */
ADD_MQ_REASON_TXT(MQRC_CONNECTION_BROKEN, "Connection to queue manager lost."); /* 2009 */
ADD_MQ_REASON_TXT(MQRC_DATA_LENGTH_ERROR, "Data length parameter not valid."); /* 2010 */
ADD_MQ_REASON_TXT(MQRC_DYNAMIC_Q_NAME_ERROR, "Name of dynamic queue not valid."); /* 2011 */
ADD_MQ_REASON_TXT(MQRC_ENVIRONMENT_ERROR, "Call not valid in environment."); /* 2012 */
ADD_MQ_REASON_TXT(MQRC_EXPIRY_ERROR, "Expiry time not valid."); /* 2013 */
ADD_MQ_REASON_TXT(MQRC_FEEDBACK_ERROR, "Feedback code not valid."); /* 2014 */
ADD_MQ_REASON_TXT(MQRC_GET_INHIBITED, "Gets inhibited for the queue."); /* 2016 */
ADD_MQ_REASON_TXT(MQRC_HANDLE_NOT_AVAILABLE, "No more handles available."); /* 2017 */
ADD_MQ_REASON_TXT(MQRC_HCONN_ERROR, "Connection handle not valid."); /* 2018 */
ADD_MQ_REASON_TXT(MQRC_HOBJ_ERROR, "Object handle not valid."); /* 2019 */
ADD_MQ_REASON_TXT(MQRC_INHIBIT_VALUE_ERROR, "Value for inhibit-get or inhibit-put queue attribute not valid."); /* 2020 */
ADD_MQ_REASON_TXT(MQRC_INT_ATTR_COUNT_ERROR, "Count of integer attributes not valid."); /* 2021 */
ADD_MQ_REASON_TXT(MQRC_INT_ATTR_COUNT_TOO_SMALL, "Not enough space allowed for integer attributes."); /* 2022 */
ADD_MQ_REASON_TXT(MQRC_INT_ATTRS_ARRAY_ERROR, "Integer attributes array not valid."); /* 2023 */
ADD_MQ_REASON_TXT(MQRC_SYNCPOINT_LIMIT_REACHED, "No more messages can be handled within current unit of work."); /* 2024 */
ADD_MQ_REASON_TXT(MQRC_MAX_CONNS_LIMIT_REACHED, "Maximum number of connections reached."); /* 2025 */
ADD_MQ_REASON_TXT(MQRC_MD_ERROR, "Message descriptor not valid."); /* 2026 */
ADD_MQ_REASON_TXT(MQRC_MISSING_REPLY_TO_Q, "Missing reply-to queue."); /* 2027 */
ADD_MQ_REASON_TXT(MQRC_MSG_TYPE_ERROR, "Message type in message descriptor not valid."); /* 2029 */
ADD_MQ_REASON_TXT(MQRC_MSG_TOO_BIG_FOR_Q, "Message length greater than maximum for queue."); /* 2030 */
ADD_MQ_REASON_TXT(MQRC_MSG_TOO_BIG_FOR_Q_MGR, "Message length greater than maximum for queue manager."); /* 2031 */
ADD_MQ_REASON_TXT(MQRC_NO_MSG_AVAILABLE, "No message available."); /* 2033 */
ADD_MQ_REASON_TXT(MQRC_NO_MSG_UNDER_CURSOR, "Browse cursor not positioned on message."); /* 2034 */
ADD_MQ_REASON_TXT(MQRC_NOT_AUTHORIZED, "Not authorized for access."); /* 2035 */
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_BROWSE, "Queue not open for browse."); /* 2036 */
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_INPUT, "Queue not open for input."); /* 2037 */
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_INQUIRE, "Queue not open for inquire."); /* 2038 */
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_OUTPUT, "Queue not open for output."); /* 2039 */
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_SET, "Queue not open for set."); /* 2040 */
ADD_MQ_REASON_TXT(MQRC_OBJECT_CHANGED, "Object definition changed since opened."); /* 2041 */
ADD_MQ_REASON_TXT(MQRC_OBJECT_IN_USE, "Object already open with conflicting options."); /* 2042 */
ADD_MQ_REASON_TXT(MQRC_OBJECT_TYPE_ERROR, "Object type not valid."); /* 2043 */
ADD_MQ_REASON_TXT(MQRC_OD_ERROR, "Object descriptor structure not valid."); /* 2044 */
ADD_MQ_REASON_TXT(MQRC_OPTION_NOT_VALID_FOR_TYPE, "Option not valid for object type."); /* 2045 */
ADD_MQ_REASON_TXT(MQRC_OPTIONS_ERROR, "Options not valid or not consistent."); /* 2046 */
ADD_MQ_REASON_TXT(MQRC_PERSISTENCE_ERROR, "Persistence not valid."); /* 2047 */
ADD_MQ_REASON_TXT(MQRC_PERSISTENT_NOT_ALLOWED, "Message on a temporary dynamic queue cannot be persistent."); /* 2048 */
ADD_MQ_REASON_TXT(MQRC_PRIORITY_EXCEEDS_MAXIMUM, "Message Priority exceeds maximum value supported."); /* 2049 */
ADD_MQ_REASON_TXT(MQRC_PRIORITY_ERROR, "Message priority not valid."); /* 2050 */
ADD_MQ_REASON_TXT(MQRC_PUT_INHIBITED, "Put calls inhibited for the queue."); /* 2051 */
ADD_MQ_REASON_TXT(MQRC_Q_DELETED, "Queue has been deleted."); /* 2052 */
ADD_MQ_REASON_TXT(MQRC_Q_FULL, "Queue already contains maximum number of messages."); /* 2053 */
ADD_MQ_REASON_TXT(MQRC_Q_NOT_EMPTY, "Queue contains one or more messages or uncommitted put or get requests."); /* 2055 */
ADD_MQ_REASON_TXT(MQRC_Q_SPACE_NOT_AVAILABLE, "No space available on disk for queue."); /* 2056 */
ADD_MQ_REASON_TXT(MQRC_Q_TYPE_ERROR, "Queue type not valid."); /* 2057 */
ADD_MQ_REASON_TXT(MQRC_Q_MGR_NAME_ERROR, "Queue manager name not valid or not known."); /* 2058 */
ADD_MQ_REASON_TXT(MQRC_Q_MGR_NOT_AVAILABLE, "Queue manager not available for connection."); /* 2059 */
ADD_MQ_REASON_TXT(MQRC_REPORT_OPTIONS_ERROR, "Report options in message descriptor not valid."); /* 2061 */
ADD_MQ_REASON_TXT(MQRC_SECOND_MARK_NOT_ALLOWED, "A message is already marked."); /* 2062 */
ADD_MQ_REASON_TXT(MQRC_SECURITY_ERROR, "Security error occurred."); /* 2063 */
ADD_MQ_REASON_TXT(MQRC_SELECTOR_COUNT_ERROR, "Count of selectors not valid."); /* 2065 */
ADD_MQ_REASON_TXT(MQRC_SELECTOR_LIMIT_EXCEEDED, "Count of selectors too big."); /* 2066 */
ADD_MQ_REASON_TXT(MQRC_SELECTOR_ERROR, "Attribute selector not valid."); /* 2067 */
ADD_MQ_REASON_TXT(MQRC_SELECTOR_NOT_FOR_TYPE, "Selector not applicable to queue type."); /* 2068 */
ADD_MQ_REASON_TXT(MQRC_SIGNAL_OUTSTANDING, "Signal outstanding for this handle."); /* 2069 */
ADD_MQ_REASON_TXT(MQRC_SIGNAL_REQUEST_ACCEPTED, "No message returned (but signal request accepted)."); /* 2070 */
ADD_MQ_REASON_TXT(MQRC_STORAGE_NOT_AVAILABLE, "Insufficient storage available."); /* 2071 */
ADD_MQ_REASON_TXT(MQRC_SYNCPOINT_NOT_AVAILABLE, "Syncpoint support not available."); /* 2072 */
ADD_MQ_REASON_TXT(MQRC_TRIGGER_CONTROL_ERROR, "Value for trigger-control attribute not valid."); /* 2075 */
ADD_MQ_REASON_TXT(MQRC_TRIGGER_DEPTH_ERROR, "Value for trigger-depth attribute not valid."); /* 2076 */
ADD_MQ_REASON_TXT(MQRC_TRIGGER_MSG_PRIORITY_ERR, "Value for trigger-message-priority attribute not valid."); /* 2077 */
ADD_MQ_REASON_TXT(MQRC_TRIGGER_TYPE_ERROR, "Value for trigger-type attribute not valid."); /* 2078 */
ADD_MQ_REASON_TXT(MQRC_TRUNCATED_MSG_ACCEPTED, "Truncated message returned (processing completed)."); /* 2079 */
ADD_MQ_REASON_TXT(MQRC_TRUNCATED_MSG_FAILED, "Truncated message returned (processing not completed)."); /* 2080 */
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_ALIAS_BASE_Q, "Unknown alias base queue."); /* 2082 */
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_OBJECT_NAME, "Unknown object name."); /* 2085 */
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_OBJECT_Q_MGR, "Unknown object queue manager."); /* 2086 */
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_REMOTE_Q_MGR, "Unknown remote queue manager."); /* 2087 */
ADD_MQ_REASON_TXT(MQRC_WAIT_INTERVAL_ERROR, "Wait interval in MQGMO not valid."); /* 2090 */
ADD_MQ_REASON_TXT(MQRC_XMIT_Q_TYPE_ERROR, "Transmission queue not local."); /* 2091 */
ADD_MQ_REASON_TXT(MQRC_XMIT_Q_USAGE_ERROR, "Transmission queue with wrong usage."); /* 2092 */
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_PASS_ALL, "Queue not open for pass all context."); /* 2093 */
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_PASS_IDENT, "Queue not open for pass identity context."); /* 2094 */
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_SET_ALL, "Queue not open for set all context."); /* 2095 */
ADD_MQ_REASON_TXT(MQRC_NOT_OPEN_FOR_SET_IDENT, "Queue not open for set identity context."); /* 2096 */
ADD_MQ_REASON_TXT(MQRC_CONTEXT_HANDLE_ERROR, "Queue handle referred to does not save context."); /* 2097 */
ADD_MQ_REASON_TXT(MQRC_CONTEXT_NOT_AVAILABLE, "Context not available for queue handle referred to."); /* 2098 */
ADD_MQ_REASON_TXT(MQRC_SIGNAL1_ERROR, "Signal field not valid."); /* 2099 */
ADD_MQ_REASON_TXT(MQRC_OBJECT_ALREADY_EXISTS, "Object already exists."); /* 2100 */
ADD_MQ_REASON_TXT(MQRC_OBJECT_DAMAGED, "Object damaged."); /* 2101 */
ADD_MQ_REASON_TXT(MQRC_RESOURCE_PROBLEM, "Insufficient system resources available."); /* 2102 */
ADD_MQ_REASON_TXT(MQRC_ANOTHER_Q_MGR_CONNECTED, "Another queue manager already connected."); /* 2103 */
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_REPORT_OPTION, "Report option(s) in message descriptor not recognized."); /* 2104 */
ADD_MQ_REASON_TXT(MQRC_STORAGE_CLASS_ERROR, "Storage class error."); /* 2105 */
ADD_MQ_REASON_TXT(MQRC_COD_NOT_VALID_FOR_XCF_Q, "COD report option not valid for XCF queue."); /* 2106 */
ADD_MQ_REASON_TXT(MQRC_XWAIT_CANCELED, "MQXWAIT call canceled."); /* 2107 */
ADD_MQ_REASON_TXT(MQRC_XWAIT_ERROR, "Invocation of MQXWAIT call not valid."); /* 2108 */
ADD_MQ_REASON_TXT(MQRC_SUPPRESSED_BY_EXIT, "Call suppressed by exit program."); /* 2109 */
ADD_MQ_REASON_TXT(MQRC_FORMAT_ERROR, "Message format not valid."); /* 2110 */
ADD_MQ_REASON_TXT(MQRC_SOURCE_CCSID_ERROR, "Source coded character set identifier not valid."); /* 2111 */
ADD_MQ_REASON_TXT(MQRC_SOURCE_INTEGER_ENC_ERROR, "Source integer encoding not recognized."); /* 2112 */
ADD_MQ_REASON_TXT(MQRC_SOURCE_DECIMAL_ENC_ERROR, "Packed-decimal encoding in message not recognized."); /* 2113 */
ADD_MQ_REASON_TXT(MQRC_SOURCE_FLOAT_ENC_ERROR, "Floating-point encoding in message not recognized."); /* 2114 */
ADD_MQ_REASON_TXT(MQRC_TARGET_CCSID_ERROR, "Target coded character set identifier not valid."); /* 2115 */
ADD_MQ_REASON_TXT(MQRC_TARGET_INTEGER_ENC_ERROR, "Target integer encoding not recognized."); /* 2116 */
ADD_MQ_REASON_TXT(MQRC_TARGET_DECIMAL_ENC_ERROR, "Packed-decimal encoding specified by receiver not recognized."); /* 2117 */
ADD_MQ_REASON_TXT(MQRC_TARGET_FLOAT_ENC_ERROR, "Floating-point encoding specified by receiver not recognized."); /* 2118 */
ADD_MQ_REASON_TXT(MQRC_NOT_CONVERTED, "Application message data not converted."); /* 2119 */
ADD_MQ_REASON_TXT(MQRC_CONVERTED_MSG_TOO_BIG, "Converted data too big for buffer."); /* 2120 */
ADD_MQ_REASON_TXT(MQRC_NO_EXTERNAL_PARTICIPANTS, "No participating resource managers registered."); /* 2121 */
ADD_MQ_REASON_TXT(MQRC_PARTICIPANT_NOT_AVAILABLE, "Participating resource manager not available."); /* 2122 */
ADD_MQ_REASON_TXT(MQRC_OUTCOME_MIXED, "Result of commit or back-out operation is mixed."); /* 2123 */
ADD_MQ_REASON_TXT(MQRC_OUTCOME_PENDING, "Result of commit operation is pending."); /* 2124 */
ADD_MQ_REASON_TXT(MQRC_BRIDGE_STARTED, "Bridge started."); /* 2125 */
ADD_MQ_REASON_TXT(MQRC_BRIDGE_STOPPED, "Bridge stopped."); /* 2126 */
ADD_MQ_REASON_TXT(MQRC_ADAPTER_STORAGE_SHORTAGE, "Insufficient storage for adapter."); /* 2127 */
ADD_MQ_REASON_TXT(MQRC_UOW_IN_PROGRESS, "Unit of work already started."); /* 2128 */
ADD_MQ_REASON_TXT(MQRC_ADAPTER_CONN_LOAD_ERROR, "Unable to load adapter connection module."); /* 2129 */
ADD_MQ_REASON_TXT(MQRC_ADAPTER_SERV_LOAD_ERROR, "Unable to load adapter service module."); /* 2130 */
ADD_MQ_REASON_TXT(MQRC_ADAPTER_DEFS_ERROR, "Adapter subsystem definition module not valid."); /* 2131 */
ADD_MQ_REASON_TXT(MQRC_ADAPTER_DEFS_LOAD_ERROR, "Unable to load adapter subsystem definition module."); /* 2132 */
ADD_MQ_REASON_TXT(MQRC_ADAPTER_CONV_LOAD_ERROR, "Unable to load data conversion services modules."); /* 2133 */
ADD_MQ_REASON_TXT(MQRC_BO_ERROR, "Begin-options structure not valid."); /* 2134 */
ADD_MQ_REASON_TXT(MQRC_DH_ERROR, "Distribution header structure not valid."); /* 2135 */
ADD_MQ_REASON_TXT(MQRC_MULTIPLE_REASONS, "Multiple reason codes returned."); /* 2136 */
ADD_MQ_REASON_TXT(MQRC_OPEN_FAILED, "Object not opened successfully."); /* 2137 */
ADD_MQ_REASON_TXT(MQRC_ADAPTER_DISC_LOAD_ERROR, "Unable to load adapter disconnection module."); /* 2138 */
ADD_MQ_REASON_TXT(MQRC_CNO_ERROR, "Connect-options structure not valid."); /* 2139 */
ADD_MQ_REASON_TXT(MQRC_CICS_WAIT_FAILED, "Wait request rejected by CICS."); /* 2140 */
ADD_MQ_REASON_TXT(MQRC_DLH_ERROR, "Dead letter header structure not valid."); /* 2141 */
ADD_MQ_REASON_TXT(MQRC_HEADER_ERROR, "MQ header structure not valid."); /* 2142 */
ADD_MQ_REASON_TXT(MQRC_SOURCE_LENGTH_ERROR, "Source length parameter not valid."); /* 2143 */
ADD_MQ_REASON_TXT(MQRC_TARGET_LENGTH_ERROR, "Target length parameter not valid."); /* 2144 */
ADD_MQ_REASON_TXT(MQRC_SOURCE_BUFFER_ERROR, "Source buffer parameter not valid."); /* 2145 */
ADD_MQ_REASON_TXT(MQRC_TARGET_BUFFER_ERROR, "Target buffer parameter not valid."); /* 2146 */
ADD_MQ_REASON_TXT(MQRC_IIH_ERROR, "IMS information header structure not valid."); /* 2148 */
ADD_MQ_REASON_TXT(MQRC_PCF_ERROR, "PCF structures not valid."); /* 2149 */
ADD_MQ_REASON_TXT(MQRC_DBCS_ERROR, "DBCS string not valid."); /* 2150 */
ADD_MQ_REASON_TXT(MQRC_OBJECT_NAME_ERROR, "Object name not valid."); /* 2152 */
ADD_MQ_REASON_TXT(MQRC_OBJECT_Q_MGR_NAME_ERROR, "Object queue-manager name not valid."); /* 2153 */
ADD_MQ_REASON_TXT(MQRC_RECS_PRESENT_ERROR, "Number of records present not valid."); /* 2154 */
ADD_MQ_REASON_TXT(MQRC_OBJECT_RECORDS_ERROR, "Object records not valid."); /* 2155 */
ADD_MQ_REASON_TXT(MQRC_RESPONSE_RECORDS_ERROR, "Response records not valid."); /* 2156 */
ADD_MQ_REASON_TXT(MQRC_ASID_MISMATCH, "Primary and home ASIDs differ."); /* 2157 */
ADD_MQ_REASON_TXT(MQRC_PMO_RECORD_FLAGS_ERROR, "Put message record flags not valid."); /* 2158 */
ADD_MQ_REASON_TXT(MQRC_PUT_MSG_RECORDS_ERROR, "Put message records not valid."); /* 2159 */
ADD_MQ_REASON_TXT(MQRC_CONN_ID_IN_USE, "Connection identifier already in use."); /* 2160 */
ADD_MQ_REASON_TXT(MQRC_Q_MGR_QUIESCING, "Queue manager quiescing."); /* 2161 */
ADD_MQ_REASON_TXT(MQRC_Q_MGR_STOPPING, "Queue manager shutting down."); /* 2162 */
ADD_MQ_REASON_TXT(MQRC_DUPLICATE_RECOV_COORD, "Recovery coordinator already exists."); /* 2163 */
ADD_MQ_REASON_TXT(MQRC_PMO_ERROR, "Put-message options structure not valid."); /* 2173 */
ADD_MQ_REASON_TXT(MQRC_API_EXIT_LOAD_ERROR, "Unable to load API crossing exit."); /* 2183 */
ADD_MQ_REASON_TXT(MQRC_REMOTE_Q_NAME_ERROR, "Remote queue name not valid."); /* 2184 */
ADD_MQ_REASON_TXT(MQRC_INCONSISTENT_PERSISTENCE, "Inconsistent persistence specification."); /* 2185 */
ADD_MQ_REASON_TXT(MQRC_GMO_ERROR, "Get-message options structure not valid."); /* 2186 */
ADD_MQ_REASON_TXT(MQRC_CICS_BRIDGE_RESTRICTION, "Requested function not supported by CICS bridge."); /* 2187 */
ADD_MQ_REASON_TXT(MQRC_STOPPED_BY_CLUSTER_EXIT, "Call rejected by cluster-workload exit."); /* 2188 */
ADD_MQ_REASON_TXT(MQRC_CLUSTER_RESOLUTION_ERROR, "Cluster name resolution failed."); /* 2189 */
ADD_MQ_REASON_TXT(MQRC_CONVERTED_STRING_TOO_BIG, "Converted string too big for field."); /* 2190 */
ADD_MQ_REASON_TXT(MQRC_TMC_ERROR, "Character trigger message structure not valid."); /* 2191 */
ADD_MQ_REASON_TXT(MQRC_PAGESET_FULL, "Page set data set full."); /* 2192 */
ADD_MQ_REASON_TXT(MQRC_PAGESET_ERROR, "Error accessing page set data set."); /* 2193 */
ADD_MQ_REASON_TXT(MQRC_NAME_NOT_VALID_FOR_TYPE, "Object name not valid for object type."); /* 2194 */
ADD_MQ_REASON_TXT(MQRC_UNEXPECTED_ERROR, "Unexpected error occurred."); /* 2195 */
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_XMIT_Q, "Unknown transmission queue."); /* 2196 */
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_DEF_XMIT_Q, "Unknown default transmission queue."); /* 2197 */
ADD_MQ_REASON_TXT(MQRC_DEF_XMIT_Q_TYPE_ERROR, "Default transmission queue not local."); /* 2198 */
ADD_MQ_REASON_TXT(MQRC_DEF_XMIT_Q_USAGE_ERROR, "Default transmission queue usage error."); /* 2199 */
ADD_MQ_REASON_TXT(MQRC_NAME_IN_USE, "Name in use."); /* 2201 */
ADD_MQ_REASON_TXT(MQRC_CONNECTION_QUIESCING, "Connection quiescing."); /* 2202 */
ADD_MQ_REASON_TXT(MQRC_CONNECTION_STOPPING, "Connection shutting down."); /* 2203 */
ADD_MQ_REASON_TXT(MQRC_ADAPTER_NOT_AVAILABLE, "Adapter not available."); /* 2204 */
ADD_MQ_REASON_TXT(MQRC_MSG_ID_ERROR, "Message-identifier error."); /* 2206 */
ADD_MQ_REASON_TXT(MQRC_CORREL_ID_ERROR, "Correlation-identifier error."); /* 2207 */
ADD_MQ_REASON_TXT(MQRC_FILE_SYSTEM_ERROR, "File-system error."); /* 2208 */
ADD_MQ_REASON_TXT(MQRC_NO_MSG_LOCKED, "No message locked."); /* 2209 */
ADD_MQ_REASON_TXT(MQRC_CONNECTION_NOT_AUTHORIZED, "Not authorized for connection."); /* 2217 */
ADD_MQ_REASON_TXT(MQRC_MSG_TOO_BIG_FOR_CHANNEL, "Message length greater than maximum for channel."); /* 2218 */
ADD_MQ_REASON_TXT(MQRC_CALL_IN_PROGRESS, "MQI call reentered before previous call complete."); /* 2219 */
ADD_MQ_REASON_TXT(MQRC_RMH_ERROR, "Reference message header structure not valid."); /* 2220 */
ADD_MQ_REASON_TXT(MQRC_Q_MGR_ACTIVE, "Queue manager created."); /* 2222 */
ADD_MQ_REASON_TXT(MQRC_Q_MGR_NOT_ACTIVE, "Queue manager unavailable."); /* 2223 */
ADD_MQ_REASON_TXT(MQRC_Q_DEPTH_HIGH, "Queue depth high limit reached or exceeded."); /* 2224 */
ADD_MQ_REASON_TXT(MQRC_Q_DEPTH_LOW, "Queue depth low limit reached or exceeded."); /* 2225 */
ADD_MQ_REASON_TXT(MQRC_Q_SERVICE_INTERVAL_HIGH, "Queue service interval high."); /* 2226 */
ADD_MQ_REASON_TXT(MQRC_Q_SERVICE_INTERVAL_OK, "Queue service interval ok."); /* 2227 */
ADD_MQ_REASON_TXT(MQRC_UNIT_OF_WORK_NOT_STARTED, "Unit of work not started."); /* 2232 */
ADD_MQ_REASON_TXT(MQRC_CHANNEL_AUTO_DEF_OK, "Automatic channel definition succeeded."); /* 2233 */
ADD_MQ_REASON_TXT(MQRC_CHANNEL_AUTO_DEF_ERROR, "Automatic channel definition failed."); /* 2234 */
ADD_MQ_REASON_TXT(MQRC_CFH_ERROR, "PCF header structure not valid."); /* 2235 */
ADD_MQ_REASON_TXT(MQRC_CFIL_ERROR, "PCF integer list parameter structure not valid."); /* 2236 */
ADD_MQ_REASON_TXT(MQRC_CFIN_ERROR, "PCF integer parameter structure not valid."); /* 2237 */
ADD_MQ_REASON_TXT(MQRC_CFSL_ERROR, "PCF string list parameter structure not valid."); /* 2238 */
ADD_MQ_REASON_TXT(MQRC_CFST_ERROR, "PCF string parameter structure not valid."); /* 2239 */
ADD_MQ_REASON_TXT(MQRC_INCOMPLETE_GROUP, "Message group not complete."); /* 2241 */
ADD_MQ_REASON_TXT(MQRC_INCOMPLETE_MSG, "Logical message not complete."); /* 2242 */
ADD_MQ_REASON_TXT(MQRC_INCONSISTENT_CCSIDS, "Message segments have differing CCSIDs."); /* 2243 */
ADD_MQ_REASON_TXT(MQRC_INCONSISTENT_ENCODINGS, "Message segments have differing encodings."); /* 2244 */
ADD_MQ_REASON_TXT(MQRC_INCONSISTENT_UOW, "Inconsistent unit-of-work specification."); /* 2245 */
ADD_MQ_REASON_TXT(MQRC_INVALID_MSG_UNDER_CURSOR, "Message under cursor not valid for retrieval."); /* 2246 */
ADD_MQ_REASON_TXT(MQRC_MATCH_OPTIONS_ERROR, "Match options not valid."); /* 2247 */
ADD_MQ_REASON_TXT(MQRC_MDE_ERROR, "Message descriptor extension not valid."); /* 2248 */
ADD_MQ_REASON_TXT(MQRC_MSG_FLAGS_ERROR, "Message flags not valid."); /* 2249 */
ADD_MQ_REASON_TXT(MQRC_MSG_SEQ_NUMBER_ERROR, "Message sequence number not valid."); /* 2250 */
ADD_MQ_REASON_TXT(MQRC_OFFSET_ERROR, "Message segment offset not valid."); /* 2251 */
ADD_MQ_REASON_TXT(MQRC_ORIGINAL_LENGTH_ERROR, "Original length not valid."); /* 2252 */
ADD_MQ_REASON_TXT(MQRC_SEGMENT_LENGTH_ZERO, "Length of data in message segment is zero."); /* 2253 */
ADD_MQ_REASON_TXT(MQRC_UOW_NOT_AVAILABLE, "Unit of work not available for the queue manager to use."); /* 2255 */
ADD_MQ_REASON_TXT(MQRC_WRONG_GMO_VERSION, "Wrong version of MQGMO supplied."); /* 2256 */
ADD_MQ_REASON_TXT(MQRC_WRONG_MD_VERSION, "Wrong version of MQMD supplied."); /* 2257 */
ADD_MQ_REASON_TXT(MQRC_GROUP_ID_ERROR, "Group identifier not valid."); /* 2258 */
ADD_MQ_REASON_TXT(MQRC_INCONSISTENT_BROWSE, "Inconsistent browse specification."); /* 2259 */
ADD_MQ_REASON_TXT(MQRC_XQH_ERROR, "Transmission queue header structure not valid."); /* 2260 */
ADD_MQ_REASON_TXT(MQRC_SRC_ENV_ERROR, "Source environment data error."); /* 2261 */
ADD_MQ_REASON_TXT(MQRC_SRC_NAME_ERROR, "Source name data error."); /* 2262 */
ADD_MQ_REASON_TXT(MQRC_DEST_ENV_ERROR, "Destination environment data error."); /* 2263 */
ADD_MQ_REASON_TXT(MQRC_DEST_NAME_ERROR, "Destination name data error."); /* 2264 */
ADD_MQ_REASON_TXT(MQRC_TM_ERROR, "Trigger message structure not valid."); /* 2265 */
ADD_MQ_REASON_TXT(MQRC_CLUSTER_EXIT_ERROR, "Cluster workload exit failed."); /* 2266 */
ADD_MQ_REASON_TXT(MQRC_CLUSTER_EXIT_LOAD_ERROR, "Unable to load cluster workload exit."); /* 2267 */
ADD_MQ_REASON_TXT(MQRC_CLUSTER_PUT_INHIBITED, "Put calls inhibited for all queues in cluster."); /* 2268 */
ADD_MQ_REASON_TXT(MQRC_NO_DESTINATIONS_AVAILABLE, "No destination queues available."); /* 2270 */
ADD_MQ_REASON_TXT(MQRC_CONNECTION_ERROR, "Error processing MQCONN call."); /* 2273 */
ADD_MQ_REASON_TXT(MQRC_OPTION_ENVIRONMENT_ERROR, "Option not valid in environment."); /* 2274 */
ADD_MQ_REASON_TXT(MQRC_CD_ERROR, "Channel definition not valid."); /* 2277 */
ADD_MQ_REASON_TXT(MQRC_CLIENT_CONN_ERROR, "Client connection fields not valid."); /* 2278 */
ADD_MQ_REASON_TXT(MQRC_CHANNEL_STOPPED_BY_USER, "Channel stopped by user."); /* 2279 */
ADD_MQ_REASON_TXT(MQRC_HCONFIG_ERROR, "Configuration handle not valid."); /* 2280 */
ADD_MQ_REASON_TXT(MQRC_FUNCTION_ERROR, "Function identifier not valid for service."); /* 2281 */
ADD_MQ_REASON_TXT(MQRC_CHANNEL_STARTED, "Channel started."); /* 2282 */
ADD_MQ_REASON_TXT(MQRC_CHANNEL_STOPPED, "Channel stopped."); /* 2283 */
ADD_MQ_REASON_TXT(MQRC_CHANNEL_CONV_ERROR, "Channel conversion error."); /* 2284 */
ADD_MQ_REASON_TXT(MQRC_SERVICE_NOT_AVAILABLE, "Underlying service not available."); /* 2285 */
ADD_MQ_REASON_TXT(MQRC_INITIALIZATION_FAILED, "Initialization failed for an undefined reason."); /* 2286 */
ADD_MQ_REASON_TXT(MQRC_TERMINATION_FAILED, "Termination failed for an undefined reason."); /* 2287 */
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_Q_NAME, "Queue name not found."); /* 2288 */
ADD_MQ_REASON_TXT(MQRC_SERVICE_ERROR, "Unexpected error occurred accessing service."); /* 2289 */
ADD_MQ_REASON_TXT(MQRC_Q_ALREADY_EXISTS, "Queue object already exists."); /* 2290 */
ADD_MQ_REASON_TXT(MQRC_USER_ID_NOT_AVAILABLE, "Unable to determine the user ID."); /* 2291 */
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_ENTITY, "Entity unknown to service."); /* 2292 */
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_AUTH_ENTITY, "Authorization entity unknown to service."); /* 2293 */
ADD_MQ_REASON_TXT(MQRC_UNKNOWN_REF_OBJECT, "Reference object unknown."); /* 2294 */
ADD_MQ_REASON_TXT(MQRC_CHANNEL_ACTIVATED, "Channel activated."); /* 2295 */
ADD_MQ_REASON_TXT(MQRC_CHANNEL_NOT_ACTIVATED, "Channel cannot be activated."); /* 2296 */
ADD_MQ_REASON_TXT(MQRC_UOW_CANCELED, "Unit of work canceled."); /* 2297 */
ADD_MQ_REASON_TXT(MQRC_SELECTOR_TYPE_ERROR, "Selector has wrong data type."); /* 2299 */
ADD_MQ_REASON_TXT(MQRC_COMMAND_TYPE_ERROR, "Command type not valid."); /* 2300 */
ADD_MQ_REASON_TXT(MQRC_MULTIPLE_INSTANCE_ERROR, "Multiple instances of system data item not valid."); /* 2301 */
ADD_MQ_REASON_TXT(MQRC_SYSTEM_ITEM_NOT_ALTERABLE, "System data item is read-only and cannot be altered."); /* 2302 */
ADD_MQ_REASON_TXT(MQRC_BAG_CONVERSION_ERROR, "Data could not be converted into a bag."); /* 2303 */
ADD_MQ_REASON_TXT(MQRC_SELECTOR_OUT_OF_RANGE, "Selector not within valid range for call."); /* 2304 */
ADD_MQ_REASON_TXT(MQRC_SELECTOR_NOT_UNIQUE, "Selector occurs more than once in bag."); /* 2305 */
ADD_MQ_REASON_TXT(MQRC_INDEX_NOT_PRESENT, "Index not present."); /* 2306 */
ADD_MQ_REASON_TXT(MQRC_STRING_ERROR, "String parameter not valid."); /* 2307 */
ADD_MQ_REASON_TXT(MQRC_ENCODING_NOT_SUPPORTED, "Encoding not supported."); /* 2308 */
ADD_MQ_REASON_TXT(MQRC_SELECTOR_NOT_PRESENT, "Selector not present in bag."); /* 2309 */
ADD_MQ_REASON_TXT(MQRC_OUT_SELECTOR_ERROR, "OutSelector parameter not valid."); /* 2310 */
ADD_MQ_REASON_TXT(MQRC_STRING_TRUNCATED, "String truncated (too long for output buffer)."); /* 2311 */
ADD_MQ_REASON_TXT(MQRC_SELECTOR_WRONG_TYPE, "Selector implies a data type not valid for call."); /* 2312 */
ADD_MQ_REASON_TXT(MQRC_INCONSISTENT_ITEM_TYPE, "Data type of item differs from previous occurrence of selector."); /* 2313 */
ADD_MQ_REASON_TXT(MQRC_INDEX_ERROR, "Index not valid."); /* 2314 */
ADD_MQ_REASON_TXT(MQRC_SYSTEM_BAG_NOT_ALTERABLE, "System bag is read-only and cannot be altered."); /* 2315 */
ADD_MQ_REASON_TXT(MQRC_ITEM_COUNT_ERROR, "ItemCount parameter not valid."); /* 2316 */
ADD_MQ_REASON_TXT(MQRC_FORMAT_NOT_SUPPORTED, "Format not supported."); /* 2317 */
ADD_MQ_REASON_TXT(MQRC_SELECTOR_NOT_SUPPORTED, "System selector not supported."); /* 2318 */
ADD_MQ_REASON_TXT(MQRC_ITEM_VALUE_ERROR, "ItemValue parameter not valid."); /* 2319 */
ADD_MQ_REASON_TXT(MQRC_HBAG_ERROR, "Bag handle not valid."); /* 2320 */
ADD_MQ_REASON_TXT(MQRC_PARAMETER_MISSING, "Parameter missing."); /* 2321 */
ADD_MQ_REASON_TXT(MQRC_CMD_SERVER_NOT_AVAILABLE, "Command server not available."); /* 2322 */
ADD_MQ_REASON_TXT(MQRC_STRING_LENGTH_ERROR, "StringLength parameter not valid."); /* 2323 */
ADD_MQ_REASON_TXT(MQRC_INQUIRY_COMMAND_ERROR, "Command code is not a recognized inquiry command."); /* 2324 */
ADD_MQ_REASON_TXT(MQRC_NESTED_BAG_NOT_SUPPORTED, "Input bag contains one or more nested bags."); /* 2325 */
ADD_MQ_REASON_TXT(MQRC_BAG_WRONG_TYPE, "Bag has wrong type for intended use."); /* 2326 */
ADD_MQ_REASON_TXT(MQRC_ITEM_TYPE_ERROR, "ItemType parameter not valid."); /* 2327 */
ADD_MQ_REASON_TXT(MQRC_SYSTEM_BAG_NOT_DELETABLE, "System bag is read-only and cannot be deleted."); /* 2328 */
ADD_MQ_REASON_TXT(MQRC_SYSTEM_ITEM_NOT_DELETABLE, "System data item is read-only and cannot be deleted."); /* 2329 */
ADD_MQ_REASON_TXT(MQRC_CODED_CHAR_SET_ID_ERROR, "Coded character set identifier parameter not valid."); /* 2330 */
ADD_MQ_REASON_TXT(MQRC_MSG_TOKEN_ERROR, "Use of message token not valid."); /* 2331 */
ADD_MQ_REASON_TXT(MQRC_MISSING_WIH, "Message data does not begin with MQWIH."); /* 2332 */
ADD_MQ_REASON_TXT(MQRC_WIH_ERROR, "MQWIH structure not valid."); /* 2333 */
ADD_MQ_REASON_TXT(MQRC_RFH_ERROR, "MQRFH structure not valid."); /* 2334 */
ADD_MQ_REASON_TXT(MQRC_RFH_STRING_ERROR, "NameValueString field not valid."); /* 2335 */
ADD_MQ_REASON_TXT(MQRC_RFH_COMMAND_ERROR, "Command not valid."); /* 2336 */
ADD_MQ_REASON_TXT(MQRC_RFH_PARM_ERROR, "Parameter not valid."); /* 2337 */
ADD_MQ_REASON_TXT(MQRC_RFH_DUPLICATE_PARM, "Duplicate parameter."); /* 2338 */
ADD_MQ_REASON_TXT(MQRC_RFH_PARM_MISSING, "Parameter missing."); /* 2339 */
ADD_MQ_REASON_TXT(MQRC_CONFIG_CREATE_OBJECT, "Create Object"); /* 2367 */
ADD_MQ_REASON_TXT(MQRC_CONFIG_CHANGE_OBJECT, "Change Object"); /* 2368 */
ADD_MQ_REASON_TXT(MQRC_CONFIG_DELETE_OBJECT, "Delete Object"); /* 2369 */
ADD_MQ_REASON_TXT(MQRC_CONFIG_REFRESH_OBJECT, "Refresh Object"); /* 2370 */
ADD_MQ_REASON_TXT(MQRCCF_CFH_TYPE_ERROR, "Type not valid."); /* 3001 */
ADD_MQ_REASON_TXT(MQRCCF_CFH_LENGTH_ERROR, "Structure length not valid."); /* 3002 */
ADD_MQ_REASON_TXT(MQRCCF_CFH_VERSION_ERROR, "Structure version number is not valid."); /* 3003 */
ADD_MQ_REASON_TXT(MQRCCF_CFH_MSG_SEQ_NUMBER_ERR, "Message sequence number not valid."); /* 3004 */
ADD_MQ_REASON_TXT(MQRCCF_CFH_CONTROL_ERROR, "Control option not valid."); /* 3005 */
ADD_MQ_REASON_TXT(MQRCCF_CFH_PARM_COUNT_ERROR, "Parameter count not valid."); /* 3006 */
ADD_MQ_REASON_TXT(MQRCCF_CFH_COMMAND_ERROR, "Command identifier not valid."); /* 3007 */
ADD_MQ_REASON_TXT(MQRCCF_COMMAND_FAILED, "Command failed."); /* 3008 */
ADD_MQ_REASON_TXT(MQRCCF_CFIN_LENGTH_ERROR, "Structure length not valid."); /* 3009 */
ADD_MQ_REASON_TXT(MQRCCF_CFST_LENGTH_ERROR, "Structure length not valid."); /* 3010 */
ADD_MQ_REASON_TXT(MQRCCF_CFST_STRING_LENGTH_ERR, "String length not valid."); /* 3011 */
ADD_MQ_REASON_TXT(MQRCCF_FORCE_VALUE_ERROR, "Force value not valid."); /* 3012 */
ADD_MQ_REASON_TXT(MQRCCF_STRUCTURE_TYPE_ERROR, "Structure type not valid."); /* 3013 */
ADD_MQ_REASON_TXT(MQRCCF_CFIN_PARM_ID_ERROR, "Parameter identifier is not valid."); /* 3014 */
ADD_MQ_REASON_TXT(MQRCCF_CFST_PARM_ID_ERROR, "Parameter identifier is not valid."); /* 3015 */
ADD_MQ_REASON_TXT(MQRCCF_MSG_LENGTH_ERROR, "Message length not valid."); /* 3016 */
ADD_MQ_REASON_TXT(MQRCCF_CFIN_DUPLICATE_PARM, "Duplicate parameter."); /* 3017 */
ADD_MQ_REASON_TXT(MQRCCF_CFST_DUPLICATE_PARM, "Duplicate parameter."); /* 3018 */
ADD_MQ_REASON_TXT(MQRCCF_PARM_COUNT_TOO_SMALL, "Parameter count too small."); /* 3019 */
ADD_MQ_REASON_TXT(MQRCCF_PARM_COUNT_TOO_BIG, "Parameter count too big."); /* 3020 */
ADD_MQ_REASON_TXT(MQRCCF_Q_ALREADY_IN_CELL, "Queue already exists in cell."); /* 3021 */
ADD_MQ_REASON_TXT(MQRCCF_Q_TYPE_ERROR, "Queue type not valid."); /* 3022 */
ADD_MQ_REASON_TXT(MQRCCF_MD_FORMAT_ERROR, "Format not valid."); /* 3023 */
ADD_MQ_REASON_TXT(MQRCCF_REPLACE_VALUE_ERROR, "Replace value not valid."); /* 3025 */
ADD_MQ_REASON_TXT(MQRCCF_CFIL_DUPLICATE_VALUE, "Duplicate parameter."); /* 3026 */
ADD_MQ_REASON_TXT(MQRCCF_CFIL_COUNT_ERROR, "Count of parameter values not valid."); /* 3027 */
ADD_MQ_REASON_TXT(MQRCCF_CFIL_LENGTH_ERROR, "Structure length not valid."); /* 3028 */
ADD_MQ_REASON_TXT(MQRCCF_QUIESCE_VALUE_ERROR, "Mode value not valid."); /* 3029 */
ADD_MQ_REASON_TXT(MQRCCF_QUIESCE_VALUE_ERROR, "Mode value not valid."); /* 3029 */
ADD_MQ_REASON_TXT(MQRCCF_MSG_SEQ_NUMBER_ERROR, "Message sequence number not valid."); /* 3030 */
ADD_MQ_REASON_TXT(MQRCCF_PING_DATA_COUNT_ERROR, "Data count not valid."); /* 3031 */
ADD_MQ_REASON_TXT(MQRCCF_PING_DATA_COMPARE_ERROR, "Ping Channel command failed."); /* 3032 */
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_TYPE_ERROR, "Channel type not valid."); /* 3034 */
ADD_MQ_REASON_TXT(MQRCCF_PARM_SEQUENCE_ERROR, "Parameter sequence not valid."); /* 3035 */
ADD_MQ_REASON_TXT(MQRCCF_XMIT_PROTOCOL_TYPE_ERR, "Transmission protocol type not valid."); /* 3036 */
ADD_MQ_REASON_TXT(MQRCCF_BATCH_SIZE_ERROR, "Batch size not valid."); /* 3037 */
ADD_MQ_REASON_TXT(MQRCCF_DISC_INT_ERROR, "Disconnection interval not valid."); /* 3038 */
ADD_MQ_REASON_TXT(MQRCCF_SHORT_RETRY_ERROR, "Short retry count not valid."); /* 3039 */
ADD_MQ_REASON_TXT(MQRCCF_SHORT_TIMER_ERROR, "Short timer value not valid."); /* 3040 */
ADD_MQ_REASON_TXT(MQRCCF_LONG_RETRY_ERROR, "Long retry count not valid."); /* 3041 */
ADD_MQ_REASON_TXT(MQRCCF_LONG_TIMER_ERROR, "Long timer not valid."); /* 3042 */
ADD_MQ_REASON_TXT(MQRCCF_SEQ_NUMBER_WRAP_ERROR, "Sequence wrap number not valid."); /* 3043 */
ADD_MQ_REASON_TXT(MQRCCF_MAX_MSG_LENGTH_ERROR, "Maximum message length not valid."); /* 3044 */
ADD_MQ_REASON_TXT(MQRCCF_PUT_AUTH_ERROR, "Put authority value not valid."); /* 3045 */
ADD_MQ_REASON_TXT(MQRCCF_PURGE_VALUE_ERROR, "Purge value not valid."); /* 3046 */
ADD_MQ_REASON_TXT(MQRCCF_CFIL_PARM_ID_ERROR, "Parameter identifier is not valid."); /* 3047 */
ADD_MQ_REASON_TXT(MQRCCF_MSG_TRUNCATED, "Message truncated."); /* 3048 */
ADD_MQ_REASON_TXT(MQRCCF_CCSID_ERROR, "Coded character-set identifier error."); /* 3049 */
ADD_MQ_REASON_TXT(MQRCCF_ENCODING_ERROR, "Encoding error."); /* 3050 */
ADD_MQ_REASON_TXT(MQRCCF_DATA_CONV_VALUE_ERROR, "Data conversion value not valid."); /* 3052 */
ADD_MQ_REASON_TXT(MQRCCF_INDOUBT_VALUE_ERROR, "In-doubt value not valid."); /* 3053 */
ADD_MQ_REASON_TXT(MQRCCF_ESCAPE_TYPE_ERROR, "Escape type not valid."); /* 3054 */
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_TABLE_ERROR, "Channel table value not valid."); /* 3062 */
ADD_MQ_REASON_TXT(MQRCCF_MCA_TYPE_ERROR, "Message channel agent type not valid."); /* 3063 */
ADD_MQ_REASON_TXT(MQRCCF_CHL_INST_TYPE_ERROR, "Channel instance type not valid."); /* 3064 */
ADD_MQ_REASON_TXT(MQRCCF_CHL_STATUS_NOT_FOUND, "Channel status not found."); /* 3065 */
ADD_MQ_REASON_TXT(MQRCCF_CFSL_DUPLICATE_PARM, "Duplicate parameter."); /* 3066 */
ADD_MQ_REASON_TXT(MQRCCF_CFSL_TOTAL_LENGTH_ERROR, "Total string length error."); /* 3067 */
ADD_MQ_REASON_TXT(MQRCCF_CFSL_COUNT_ERROR, "Name count value not valid."); /* 3068 */
ADD_MQ_REASON_TXT(MQRCCF_CFSL_STRING_LENGTH_ERR, "String length not valid."); /* 3069 */
ADD_MQ_REASON_TXT(MQRCCF_Q_MGR_CCSID_ERROR, "Queue manager coded character set identifier error."); /* 3086 */
ADD_MQ_REASON_TXT(MQRCCF_CLUSTER_NAME_CONFLICT, "ClusterName and ClusterNamelist attributes conflict."); /* 3088 */
ADD_MQ_REASON_TXT(MQRCCF_REPOS_NAME_CONFLICT, "RepositoryName and RepositoryNamelist attributes conflict."); /* 3089 */
ADD_MQ_REASON_TXT(MQRCCF_CLUSTER_Q_USAGE_ERROR, "Cluster queue cannot be a transmission queue."); /* 3090 */
ADD_MQ_REASON_TXT(MQRCCF_ACTION_VALUE_ERROR, "Action value not valid."); /* 3091 */
ADD_MQ_REASON_TXT(MQRCCF_COMMS_LIBRARY_ERROR, "Library for requested communications protocol could not be loaded."); /* 3092 */
ADD_MQ_REASON_TXT(MQRCCF_NETBIOS_NAME_ERROR, "NetBIOS listener name not defined."); /* 3093 */
ADD_MQ_REASON_TXT(MQRCCF_CFST_CONFLICTING_PARM, "Conflicting parameters."); /* 3095 */
ADD_MQ_REASON_TXT(MQRCCF_FILTER_ERROR, "Content based filter expression not valid."); /* 3150 */
ADD_MQ_REASON_TXT(MQRCCF_WRONG_USER, "Wrong user."); /* 3151 */
ADD_MQ_REASON_TXT(MQRCCF_OBJECT_ALREADY_EXISTS, "Object already exists."); /* 4001 */
ADD_MQ_REASON_TXT(MQRCCF_OBJECT_WRONG_TYPE, "Object has wrong type."); /* 4002 */
ADD_MQ_REASON_TXT(MQRCCF_LIKE_OBJECT_WRONG_TYPE, "New and existing objects have different type."); /* 4003 */
ADD_MQ_REASON_TXT(MQRCCF_OBJECT_OPEN, "Object is open."); /* 4004 */
ADD_MQ_REASON_TXT(MQRCCF_ATTR_VALUE_ERROR, "Attribute value not valid."); /* 4005 */
ADD_MQ_REASON_TXT(MQRCCF_UNKNOWN_Q_MGR, "Queue manager not known."); /* 4006 */
ADD_MQ_REASON_TXT(MQRCCF_Q_WRONG_TYPE, "Action not valid for the queue of specified type."); /* 4007 */
ADD_MQ_REASON_TXT(MQRCCF_OBJECT_NAME_ERROR, "Object name not valid."); /* 4008 */
ADD_MQ_REASON_TXT(MQRCCF_ALLOCATE_FAILED, "Allocation failed."); /* 4009 */
ADD_MQ_REASON_TXT(MQRCCF_HOST_NOT_AVAILABLE, "Remote system not available."); /* 4010 */
ADD_MQ_REASON_TXT(MQRCCF_CONFIGURATION_ERROR, "Configuration error."); /* 4011 */
ADD_MQ_REASON_TXT(MQRCCF_CONNECTION_REFUSED, "Connection refused."); /* 4012 */
ADD_MQ_REASON_TXT(MQRCCF_ENTRY_ERROR, "Invalid connection name."); /* 4013 */
ADD_MQ_REASON_TXT(MQRCCF_SEND_FAILED, "Send failed."); /* 4014 */
ADD_MQ_REASON_TXT(MQRCCF_RECEIVED_DATA_ERROR, "Received data error."); /* 4015 */
ADD_MQ_REASON_TXT(MQRCCF_RECEIVE_FAILED, "Receive failed."); /* 4016 */
ADD_MQ_REASON_TXT(MQRCCF_CONNECTION_CLOSED, "Connection closed."); /* 4017 */
ADD_MQ_REASON_TXT(MQRCCF_NO_STORAGE, "Not enough storage available."); /* 4018 */
ADD_MQ_REASON_TXT(MQRCCF_NO_COMMS_MANAGER, "Communications manager not available."); /* 4019 */
ADD_MQ_REASON_TXT(MQRCCF_LISTENER_NOT_STARTED, "Listener not started."); /* 4020 */
ADD_MQ_REASON_TXT(MQRCCF_BIND_FAILED, "Bind failed."); /* 4024 */
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_INDOUBT, "Channel in-doubt."); /* 4025 */
ADD_MQ_REASON_TXT(MQRCCF_MQCONN_FAILED, "MQCONN call failed."); /* 4026 */
ADD_MQ_REASON_TXT(MQRCCF_MQOPEN_FAILED, "MQOPEN call failed."); /* 4027 */
ADD_MQ_REASON_TXT(MQRCCF_MQGET_FAILED, "MQGET call failed."); /* 4028 */
ADD_MQ_REASON_TXT(MQRCCF_MQPUT_FAILED, "MQPUT call failed."); /* 4029 */
ADD_MQ_REASON_TXT(MQRCCF_PING_ERROR, "Ping error."); /* 4030 */
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_IN_USE, "Channel in use."); /* 4031 */
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_NOT_FOUND, "Channel not found."); /* 4032 */
ADD_MQ_REASON_TXT(MQRCCF_UNKNOWN_REMOTE_CHANNEL, "Remote channel not known."); /* 4033 */
ADD_MQ_REASON_TXT(MQRCCF_REMOTE_QM_UNAVAILABLE, "Remote queue manager not available."); /* 4034 */
ADD_MQ_REASON_TXT(MQRCCF_REMOTE_QM_TERMINATING, "Remote queue manager terminating."); /* 4035 */
ADD_MQ_REASON_TXT(MQRCCF_MQINQ_FAILED, "MQINQ call failed."); /* 4036 */
ADD_MQ_REASON_TXT(MQRCCF_NOT_XMIT_Q, "Queue is not a transmission queue."); /* 4037 */
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_DISABLED, "Channel disabled."); /* 4038 */
ADD_MQ_REASON_TXT(MQRCCF_USER_EXIT_NOT_AVAILABLE, "User exit not available."); /* 4039 */
ADD_MQ_REASON_TXT(MQRCCF_COMMIT_FAILED, "Commit failed."); /* 4040 */
ADD_MQ_REASON_TXT(MQRCCF_WRONG_CHANNEL_TYPE, "Parameter not allowed for this channel type."); /* 4041 */
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_ALREADY_EXISTS, "Channel already exists."); /* 4042 */
ADD_MQ_REASON_TXT(MQRCCF_DATA_TOO_LARGE, "Data too large."); /* 4043 */
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_NAME_ERROR, "Channel name error."); /* 4044 */
ADD_MQ_REASON_TXT(MQRCCF_XMIT_Q_NAME_ERROR, "Transmission queue name error."); /* 4045 */
ADD_MQ_REASON_TXT(MQRCCF_MCA_NAME_ERROR, "Message channel agent name error."); /* 4047 */
ADD_MQ_REASON_TXT(MQRCCF_SEND_EXIT_NAME_ERROR, "Channel send exit name error."); /* 4048 */
ADD_MQ_REASON_TXT(MQRCCF_SEC_EXIT_NAME_ERROR, "Channel security exit name error."); /* 4049 */
ADD_MQ_REASON_TXT(MQRCCF_MSG_EXIT_NAME_ERROR, "Channel message exit name error."); /* 4050 */
ADD_MQ_REASON_TXT(MQRCCF_RCV_EXIT_NAME_ERROR, "Channel receive exit name error."); /* 4051 */
ADD_MQ_REASON_TXT(MQRCCF_XMIT_Q_NAME_WRONG_TYPE, "Transmission queue name not allowed for this channel type."); /* 4052 */
ADD_MQ_REASON_TXT(MQRCCF_MCA_NAME_WRONG_TYPE, "Message channel agent name not allowed for this channel type."); /* 4053 */
ADD_MQ_REASON_TXT(MQRCCF_DISC_INT_WRONG_TYPE, "Disconnection interval not allowed for this channel type."); /* 4054 */
ADD_MQ_REASON_TXT(MQRCCF_SHORT_RETRY_WRONG_TYPE, "Short retry parameter not allowed for this channel type."); /* 4055 */
ADD_MQ_REASON_TXT(MQRCCF_SHORT_TIMER_WRONG_TYPE, "Short timer parameter not allowed for this channel type."); /* 4056 */
ADD_MQ_REASON_TXT(MQRCCF_LONG_RETRY_WRONG_TYPE, "Long retry parameter not allowed for this channel type."); /* 4057 */
ADD_MQ_REASON_TXT(MQRCCF_LONG_TIMER_WRONG_TYPE, "Long timer parameter not allowed for this channel type."); /* 4058 */
ADD_MQ_REASON_TXT(MQRCCF_PUT_AUTH_WRONG_TYPE, "Put authority parameter not allowed for this channel type."); /* 4059 */
ADD_MQ_REASON_TXT(MQRCCF_KEEP_ALIVE_INT_ERROR, "Keepalive interval not valid."); /* 4060 */
ADD_MQ_REASON_TXT(MQRCCF_MISSING_CONN_NAME, "Connection name parameter required but missing."); /* 4061 */
ADD_MQ_REASON_TXT(MQRCCF_CONN_NAME_ERROR, "Error in connection name parameter."); /* 4062 */
ADD_MQ_REASON_TXT(MQRCCF_MQSET_FAILED, "MQSET call failed."); /* 4063 */
ADD_MQ_REASON_TXT(MQRCCF_CHANNEL_NOT_ACTIVE, "Channel not active."); /* 4064 */
ADD_MQ_REASON_TXT(MQRCCF_TERMINATED_BY_SEC_EXIT, "Channel terminated by security exit."); /* 4065 */
ADD_MQ_REASON_TXT(MQRCCF_DYNAMIC_Q_SCOPE_ERROR, "Dynamic queue scope error."); /* 4067 */
ADD_MQ_REASON_TXT(MQRCCF_CELL_DIR_NOT_AVAILABLE, "Cell directory is not available."); /* 4068 */
ADD_MQ_REASON_TXT(MQRCCF_MR_COUNT_ERROR, "Message retry count not valid."); /* 4069 */
ADD_MQ_REASON_TXT(MQRCCF_MR_COUNT_WRONG_TYPE, "Message-retry count parameter not allowed for this channel type."); /* 4070 */
ADD_MQ_REASON_TXT(MQRCCF_MR_EXIT_NAME_ERROR, "Channel message-retry exit name error."); /* 4071 */
ADD_MQ_REASON_TXT(MQRCCF_MR_EXIT_NAME_WRONG_TYPE, "Message-retry exit parameter not allowed for this channel type."); /* 4072 */
ADD_MQ_REASON_TXT(MQRCCF_MR_INTERVAL_ERROR, "Message retry interval not valid."); /* 4073 */
ADD_MQ_REASON_TXT(MQRCCF_MR_INTERVAL_WRONG_TYPE, "Message-retry interval parameter not allowed for this channel type."); /* 4074 */
ADD_MQ_REASON_TXT(MQRCCF_NPM_SPEED_ERROR, "Nonpersistent message speed not valid."); /* 4075 */
ADD_MQ_REASON_TXT(MQRCCF_NPM_SPEED_WRONG_TYPE, "Nonpersistent message speed parameter not allowed for this channel type."); /* 4076 */
ADD_MQ_REASON_TXT(MQRCCF_HB_INTERVAL_ERROR, "Heartbeat interval not valid."); /* 4077 */
ADD_MQ_REASON_TXT(MQRCCF_HB_INTERVAL_WRONG_TYPE, "Heartbeat interval parameter not allowed for this channel type."); /* 4078 */
ADD_MQ_REASON_TXT(MQRCCF_CHAD_ERROR, "Channel automatic definition error."); /* 4079 */
ADD_MQ_REASON_TXT(MQRCCF_CHAD_WRONG_TYPE, "Channel automatic definition parameter not allowed for this channel type."); /* 4080 */
ADD_MQ_REASON_TXT(MQRCCF_CHAD_EVENT_ERROR, "Channel automatic definition event error."); /* 4081 */
ADD_MQ_REASON_TXT(MQRCCF_CHAD_EVENT_WRONG_TYPE, "Channel automatic definition event parameter not allowed for this channel type."); /* 4082 */
ADD_MQ_REASON_TXT(MQRCCF_CHAD_EXIT_ERROR, "Channel automatic definition exit name error."); /* 4083 */
ADD_MQ_REASON_TXT(MQRCCF_CHAD_EXIT_WRONG_TYPE, "Channel automatic definition exit parameter not allowed for this channel type."); /* 4084 */
ADD_MQ_REASON_TXT(MQRCCF_SUPPRESSED_BY_EXIT, "Action suppressed by exit program."); /* 4085 */
ADD_MQ_REASON_TXT(MQRCCF_BATCH_INT_ERROR, "Batch interval not valid."); /* 4086 */
ADD_MQ_REASON_TXT(MQRCCF_BATCH_INT_WRONG_TYPE, "Batch interval parameter not allowed for this channel type."); /* 4087 */
ADD_MQ_REASON_TXT(MQRCCF_NET_PRIORITY_ERROR, "Network priority value is not valid."); /* 4088 */
ADD_MQ_REASON_TXT(MQRCCF_NET_PRIORITY_WRONG_TYPE, "Network priority parameter not allowed for this channel type."); /* 4089 */
ADD_MQ_REASON_TXT(MQRC_NEGATIVE_LENGTH, "Length is negative."); /* 6117 */
