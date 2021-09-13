#include <iostream>

#include <metaf.hpp>

using namespace metaf;


auto report =
	  "KDDC 112052Z AUTO 19023G34KT 7SM CLR 33/16 A2992"
	  " RMK AO2 PK WND 20038/2033 SLP096 T03330156 58018";

auto constexpr is_error = [](ReportError re){
    return re == ReportError::NONE ? "no error, parsed successfully" : "Some error";
};

auto constexpr report_type = [](ReportType rt){
    switch (rt) {
        case ReportType::METAR: return "METAR";
        case ReportType::TAF: return "TAF";
        default: return "UNKNOWN";
    }
};


int main() {
  	std::cout << "Parsing report: " << report << "\n";
  	const auto result = Parser::parse(report);
  	std::cout << "Parse error: "; 
  	std::cout << is_error(result.reportMetadata.error) << "\n";
  	std::cout << "Detected report type: "; 
  	std::cout << report_type(result.reportMetadata.type) << "\n";
  	std::cout << result.groups.size() << " groups parsed\n";
}
