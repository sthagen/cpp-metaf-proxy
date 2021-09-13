#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <array>
#include <string>
#include <sstream>

#include <doctest/doctest.h>

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

TEST_SUITE ("Example derived tests.") {
    TEST_CASE ("No error in parsing the example report.") {
        /* Example snippet:
         *
         * const auto result = Parser::parse(report);
         * std::cout << "Parse error: "; 
         * std::cout << is_error(result.reportMetadata.error) << "\n";
         */
        const auto result = Parser::parse(report);
        REQUIRE(is_error(result.reportMetadata.error) == "no error, parsed successfully");
    }

    TEST_CASE ("Report type of the example report.") {
        /* Example snippet:
         *
         * const auto result = Parser::parse(report);
         * std::cout << report_type(result.reportMetadata.type) << "\n";
         */
        const auto result = Parser::parse(report);
        REQUIRE(report_type(result.reportMetadata.type) == "METAR");
    }

    TEST_CASE ("Number of groups in the example report.") {
        /* Example snippet:
         *
         * const auto result = Parser::parse(report);
         * std::cout << result.groups.size() << " groups parsed\n";
         */
        const auto result = Parser::parse(report);
        REQUIRE(result.groups.size() == 14);
    }
}
