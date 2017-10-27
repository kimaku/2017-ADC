/**
* \file DiodeClipperFilter_v4.h
*/

#ifndef ATKADC_DIODECLIPPERFILTERV4_H
#define ATKADC_DIODECLIPPERFILTERV4_H

#include <memory>

#include <ATK/Core/TypedBaseFilter.h>
#include <ATK/Distortion/config.h>

namespace ATK
{
	template<typename Function, int max_iterations, bool check_convergence>
	class ScalarNewtonRaphson;
}
namespace ATKADC
{
	/// Diode clipper filter, based on a trapezoidal rule
	template<typename DataType_>
	class DiodeClipperFilterv4 final : public ATK::TypedBaseFilter<DataType_>
	{
		class SimpleOverdriveFunction;
	public:
		/// Simplify parent calls
		typedef ATK::TypedBaseFilter<DataType_> Parent;
		using typename Parent::DataType;
		using Parent::converted_inputs;
		using Parent::outputs;
		using Parent::input_sampling_rate;
		using Parent::output_sampling_rate;

		using Parent::input_delay;
		using Parent::output_delay;
	public:
		/*!
		* @brief Constructor
		*/
		DiodeClipperFilterv4();
		/// Destructor
		~DiodeClipperFilterv4();

	protected:
		void setup() final;
		void process_impl(std::size_t size) const final;

	private:
		std::unique_ptr<ATK::ScalarNewtonRaphson<SimpleOverdriveFunction, 10, true> > optimizer;
	};
}

#endif
